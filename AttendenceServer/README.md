# 考勤系统模块总结

本考勤系统基于 Qt（用于界面和网络通信）和 OpenCV（用于图像处理），结合 SeetaFace 引擎进行人脸识别，实现员工考勤管理。系统分为以下模块：**main.cpp**（应用初始化与数据库设置）、**AttendenceVim（服务器端）**、**RegisterVim（注册模块）**、**SelectVim（查询模块）**、**QFaceObject（人脸识别封装类）**以及 Qt 自动生成的 **moc_\*.cpp** 文件。



## main.cpp：应用启动与数据库初始化

- **应用程序初始化**：创建 `QApplication` 对象启动 Qt 应用；注册自定义元类型 `cv::Mat` 和 `int64_t`，以便在信号槽中传递 OpenCV 图像和人脸 ID。
- **数据库连接**：使用 `QSqlDatabase::addDatabase("QSQLITE")` 连接 SQLite 数据库，数据库文件命名为 “server.db”。打开数据库失败时输出错误信息并退出。
- **创建表结构**：通过 `QSqlQuery` 执行 SQL 语句，创建员工信息表和考勤记录表。其中：
  - **员工表** `employee` 包含 `employeeID`（自增主键）、`name`、`sex`、`birthday`、`address`、`phone`、`faceID`（人脸库 ID，唯一）和 `headfile`（头像文件路径）字段。
  - **考勤表** `attendance`（或拼写 `attendence`）包含 `attendaceID`（自增主键）、`employeeID`、`attendaceTime`（默认当前时间戳）字段。
- **启动主界面**：创建并显示 `AttendenceVim` 窗口（服务器端界面），然后进入事件循环。整个系统启动时，完成 Qt 环境初始化、数据库准备和界面显示。

## AttendenceVim（服务器端核心）：TCP 通信与考勤处理

- **界面与服务端监听**：`AttendenceVim` 构造函数中调用 `ui->setupUi(this)` 设置界面；创建 `QTcpServer` 对象并监听本机 6000 端口，等待客户端（考勤设备）连接。
- **多线程与人脸识别集成**：创建一个 `QThread` 线程，把 `QFaceObject` 对象移动到该线程中执行。通过 `connect` 将本类的 `query(cv::Mat&)` 信号连接到 `QFaceObject::face_query` 槽函数，同时将 `QFaceObject::send_faceid(int64_t)` 信号连接到本类的 `recv_faceid(int64_t)` 槽。这样，当收到人脸图像后，可异步调用人脸识别模块。
- **连接客户端**：`accept_client()` 槽函数在有客户端连接时被触发，使用 `mServer.nextPendingConnection()` 获取 `QTcpSocket` 对象 `msocket`，并连接其 `readyRead` 信号到本类的 `read_data()` 函数。
- **接收与解码图像**：`read_data()` 中通过 `QDataStream` 从 `msocket` 读取数据。首先读取一个整数 `bsize` 作为后续图像数据长度；然后当缓冲区数据足够时读出 `QByteArray data`。用 `QPixmap::loadFromData(data, "jpg")` 将字节流解码为图片并显示在界面标签 `picLb` 上。同时，将字节流通过 OpenCV `cv::imdecode()` 解码为 `cv::Mat faceImage`。
- **人脸识别流程**：接收到图像后，发射 `query(faceImage)` 信号，由 `QFaceObject::face_query` 在后台线程执行人脸匹配。匹配结果通过 `send_faceid` 信号传回，再由 `recv_faceid(faceid)` 处理。
- **考勤记录处理**：`recv_faceid(int64_t faceid)` 中先检查识别结果：
  - 如果 `faceid<0`（未识别到有效人脸），则直接通过 `msocket->write()` 向客户端发送空白 JSON（所有字段为空）表示失败。
  - 若识别成功，则使用 `QSqlTableModel model` 过滤查询 `employee` 表中 `faceID=faceid`。找到匹配的员工记录后，从 `QSqlRecord record` 中提取 `employeeID` 和 `name`，构造包含工号、姓名、部门和当前时间的 JSON 字符串。
  - 将该考勤记录插入 `attendance` 表（只写入 `employeeID`，时间字段自动填充当前时刻）。插入失败时，同样返回空白 JSON。最后，通过 `msocket->write()` 将 JSON 发送回客户端，上层可显示或存档。
- **总结**：`AttendenceVim` 作为服务器端核心，通过 TCP 接收客户端推送的人脸图像，调用人脸识别模块获取 `faceID`，再查询数据库完成考勤记录写入，并将识别结果反馈给客户端。

## RegisterVim（用户注册）：采集和注册新员工人脸

- **界面元素**：`RegisterVim` 界面提供姓名、性别、生日、地址、电话等输入框，以及头像显示标签 `headpicLb` 和按钮（打开摄像头、拍照、选择图片、重置、注册等）。
- **实时预览摄像头**：点击“打开摄像头”按钮时，调用 `on_videoswitchBt_clicked()` 打开默认摄像头 `cap`，启动定时器（如每 100ms 执行一次 `timerEvent()`）。在 `timerEvent()` 中不断从摄像头读取帧 `cap >> image`，将 BGR 转为 RGB，再转换为 `QImage` 显示在 `headpicLb`。点击“关闭摄像头”则停止定时器并释放 `cap`。
- **保存拍摄图像**：在摄像头打开状态下点击“拍照”按钮 (`on_cameraBt_clicked()`)，将当前 `image` 保存到 `data` 目录下（文件名根据用户名 Base64 编码生成）。保存后停止定时器、关闭摄像头；`headpicLb` 中会显示新头像。
- **本地选图**：点击“选择图片”按钮 (`on_addpicBt_clicked()`) 弹出文件对话框选择已有头像图像，选定后将路径写入 `picFileEdit` 并用 `QPixmap` 显示在 `headpicLb`。
- **注册提交**：点击“注册”按钮 (`on_registerBt_clicked()`) 后，读取头像图像文件并创建 `QFaceObject faceobj`。调用 `faceobj.face_register(image)` 将人脸注册到 SeetaFace 库中，返回唯一的 。如果注册失败（`faceID<0`），弹出错误提示。否则，将头像图像保存到 `./data/` 目录下，并准备向数据库插入记录。
  - 构造 `QSqlTableModel`，并创建新记录 `QSqlRecord`，设置各字段值：姓名、性别（单选按钮）、生日、地址、电话、`faceID`、头像路径 `headfile`。
  - 使用 `model.insertRecord(0, record)` 将记录插入 `employee` 表；插入成功后弹出“注册成功”提示并调用 `model.submitAll()` 提交。否则弹出失败提示。
- **重置功能**：点击“重置”按钮 `on_resetBt_clicked()` 可清空所有输入框，生日重置为当前日期。
- **小结**：`RegisterVim` 实现新员工人脸注册。它支持实时拍摄和文件选图两种方式获取头像，利用 `QFaceObject` 将人脸图像注册进人脸库得到 `faceID`，并将员工信息连同 `faceID` 存入数据库供后续识别使用。

## SelectVim（查询模块）：员工和考勤记录查询

- **界面与选项**：`SelectVim` 界面提供单选按钮“员工信息”和“考勤记录”，下方为 `QTableView` 用于展示查询结果。用户选择类型后点击“查询”按钮触发 `on_selectBt_clicked()`。
- **查询逻辑**：函数中根据选中单选框调用 `model->setTable()` 设置要查询的表名：若选“员工信息”则 `employee` 表，否则（注：代码中拼写为 `attendence`，应与实际表名匹配）使用 `attendance` 表。然后调用 `model->select()` 执行查询，并通过 `ui->tableView->setModel(model)` 将结果显示在界面表格中。
- **拓展**：界面和代码可进一步扩展过滤条件（示例代码中注释了 `setFilter`），目前查询功能主要做全表显示。
- **总结**：`SelectVim` 利用 `QSqlTableModel` 简单实现数据查询和显示，支持员工信息表和考勤记录表的切换查看。

## QFaceObject（人脸识别封装类）：基于 SeetaFace 的注册与识别

- **初始化 SeetaFace**：在构造函数 `QFaceObject()` 中，使用三组 `seeta::ModelSetting` 配置文件加载人脸检测（`fd_2_00.dat`）、人脸关键点（`pd_2_00_pts5.dat`）和人脸识别（`fr_2_10.dat`）模型。创建 `seeta::FaceEngine` 对象 `fengpinptr` 并加载存储人脸特征的数据库文件 `face.db`。
- **人脸注册**：`face_register(cv::Mat &faceImage)` 方法将 OpenCV 图像转换为 `SeetaImageData` 格式，调用 `fengpinptr->Register(simage)` 将人脸特征存入引擎，得到一个全局唯一的 `faceid`。如果注册成功（`faceid>=0`），则调用 `fengpinptr->Save("./face.db")` 将更新后的数据库保存到文件p。函数返回 `faceid`。
- **人脸识别查询**：`face_query(cv::Mat &faceImage)` 方法同样转换图像格式后调用 `fengpinptr->Query(simage, &similarity)`。函数获取返回的人脸 ID 和匹配相似度。如果相似度超过阈值（代码中为 0.7），则通过信号 `send_faceid(faceid)` 发送匹配到的 `faceid`；否则发送 `-1` 表示未识别。（同时函数返回 `faceid`）。
- **线程与信号**：由于 `face_query` 是耗时操作，实际运行时通过信号槽在单独线程执行，以免阻塞 UI。说明将 `QFaceObject` 移动到新线程中，并连接信号。
- **总结**：`QFaceObject` 对 SeetaFace 引擎进行了封装，实现了人脸注册（添加人脸到数据库）和识别查询的功能。通过统一接口，其他模块无需关心底层算法细节，仅通过调用 `face_register` 和触发 `face_query` 信号来完成相应功能。

## moc_*.cpp 文件：Qt 信号槽元数据支持

- Qt 的 **MOC**（Meta-Object Compiler）会自动从 `.h` 文件生成 `moc_*.cpp` 文件，用于处理信号与槽的元对象信息（包含类名、信号/槽函数签名等）。
- 这些文件不包含业务逻辑，仅由 Qt 编译流程生成，可支持信号槽机制的运行时反射。每次修改包含 `Q_OBJECT` 的类后会更新相应 `moc_` 文件。开发者一般无需直接编辑或调用这些文件；它们在编译时自动被链接进程序。