# FaceAttendence 人脸考勤系统分析

## 概述整体功能

FaceAttendence 是一个基于 Qt 图形界面开发的人脸考勤系统，集成了 OpenCV 进行图像处理。系统通过摄像头实时采集视频帧，使用级联分类器检测人脸；当检测到稳定人脸后，将当前帧编码为 JPEG 格式，并通过 TCP 网络发送到服务器。服务器返回包含员工编号、姓名、部门和时间等考勤信息的 JSON 数据，客户端解析后在界面上显示员工信息和头像。简而言之，该系统实现了“摄像头采集 → 人脸检测 → 发送给服务器 → 接收考勤结果 → 界面展示”的完整流程。

## 类结构分析

系统的核心类是 **FaceAttendence**，继承自 `QMainWindow`，主要成员变量和函数如下：

- **成员变量**：
  - `Ui::FaceAttendence *ui`：指向由 Qt Designer 生成的用户界面对象，用于访问界面上的各控件（如标签、编辑框等）。
  - `cv::VideoCapture cap`：OpenCV 的摄像头对象，用于打开和读取摄像头图像。
  - `cv::CascadeClassifier cascade`：人脸检测的级联分类器对象，用于加载 Haar 特征人脸检测模型。
  - `QTcpSocket msocket`：TCP 客户端套接字，用于与考勤服务器建立连接并发送/接收数据。
  - `QTimer mtimer`：Qt 定时器，用于定时发起服务器连接尝试（每隔 5 秒）。
  - `int flag`：状态标志，用来标识当前是否持续检测到同一张人脸以及控制图像发送频率。
  - `cv::Mat faceMat`：存储检测到的人脸区域图像，用于本地保存或后续处理。
- **成员函数**：
  - 构造函数 `FaceAttendence(QWidget *parent = nullptr)`：初始化界面并配置各模块。其作用包括 `ui->setupUi(this)` 设置界面，打开摄像头 (`cap.open("/dev/video0")`)、启动画面捕获定时器 (`startTimer(100)`)；加载人脸检测模型 (`cascade.load(...)`)；设置网络信号和槽连接（断开连接触发重连、连接成功停止重连、数据就绪触发接收处理）；启动 5 秒周期的连接定时器 `mtimer`；初始化 `flag` 和隐藏信息面板。
  - 析构函数 `~FaceAttendence()`：清理界面对象。
  - `void timerEvent(QTimerEvent *e)`：重载的定时器事件函数，每 100 毫秒被触发一次。在此函数中执行摄像头抓帧、图像预处理（缩放、转灰度）、人脸检测，以及根据检测结果执行后续处理和界面更新。
  - 槽函数 `void timer_connect()`：定时器触发的槽，用于尝试连接服务器（调用 `msocket.connectToHost("192.168.1.117",6000)`）。
  - 槽函数 `void stop_connect()`：当与服务器连接成功时触发，停止连接尝试定时器 `mtimer`。
  - 槽函数 `void start_connect()`：当与服务器断开连接时触发，重启定时器 `mtimer` 开始新的连接尝试。
  - 槽函数 `void recv_data()`：处理从服务器接收到的数据。读取全部字节流并解析为 JSON 对象，提取员工编号、姓名、部门和考勤时间，然后更新界面上的对应文本框。最后显示头像容器并设置头像样式。

这些成员变量和函数共同协作，实现了摄像头采集、人脸检测、网络通信和界面展示等功能模块。

## 初始化与启动流程

1. **主函数启动**：程序从 `main.cpp` 开始执行，创建 `QApplication` 对象，然后实例化 `FaceAttendence` 并调用 `w.show()` 显示主窗口，最后进入事件循环 `a.exec()`file-cwdqxwz8zu5edpqhuajq1t。
2. **界面初始化**：`FaceAttendence` 构造函数中调用 `ui->setupUi(this)` 完成界面控件的初始化。
3. **打开摄像头并启动定时器**：构造函数调用 `cap.open("/dev/video0")` 打开摄像头设备file-crejcngjkpukkryjjpflje，并通过 `startTimer(100)` 启动一个 100 毫秒间隔的定时器，用于定时采集图像。
4. **加载人脸检测模型**：使用 `cascade.load()` 加载 Haar 级联分类器文件（路径需根据开发板调整）file-crejcngjkpukkryjjpflje。
5. **配置网络信号**：将 `msocket` 的 `connected`、`disconnected`、`readyRead` 信号分别连接到对应的槽函数 `stop_connect`、`start_connect`、`recv_data`file-crejcngjkpukkryjjpflje。
6. **启动连接定时器**：设置 `mtimer` 每隔 5 秒触发一次，用于执行 `timer_connect()` 尝试连接服务器，并立即启动该定时器file-crejcngjkpukkryjjpflje。
7. **事件循环运行**：主窗口显示后，Qt 事件循环开始处理定时器、网络等异步事件，系统正式进入运行状态。

## 摄像头与人脸识别

系统通过定时器驱动摄像头采集和人脸识别，主要流程如下：

- **定时采集**：每隔 100 毫秒，`timerEvent()` 被调用一次。在该函数中，首先使用 `cap.grab()` 和 `cap.read()` 读取一帧图像file-crejcngjkpukkryjjpflje。获取到的图像被缩放到 480×480 大小file-crejcngjkpukkryjjpflje，并转换为灰度图像以便后续处理file-crejcngjkpukkryjjpflje（虽然检测使用了彩色图像，此处灰度转换是可选的）。
- **人脸检测**：使用 `cascade.detectMultiScale(srcImage, faceRects)` 对当前帧进行多尺度人脸检测file-crejcngjkpukkryjjpflje。检测结果保存在 `faceRects` 向量中，若发现至少一个人脸，就取第一个人脸的矩形区域 `rect = faceRects.at(0)`。
- **移动人脸标记**：如果检测到人脸，程序将用户界面上 `ui->head` 标签的位置移动到该人脸区域的 `(x,y)` 坐标file-crejcngjkpukkryjjpflje，在视频图像上标记人脸位置。
- **发送图像逻辑**：引入 `flag` 变量控制发送时机。每检测到一帧人脸，`flag` 自增；当 `flag > 2` 时（连续检测到同一张人脸一段时间后），执行发送操作：
  - 使用 `cv::imencode(".jpg", srcImage, buf)` 将当前帧编码为 JPEG 数据file-crejcngjkpukkryjjpflje。
  - 将 JPEG 数据写入 `QByteArray`，并使用 `QDataStream` 打包数据长度 `backsize` 和图像数据file-crejcngjkpukkryjjpflje。注意设置 `stream.setVersion(QDataStream::Qt_5_14)` 保证数据格式与服务器一致。
  - 调用 `msocket.write(sendData)` 将封装后的数据发送给服务器file-crejcngjkpukkryjjpflje。
  - 发送完成后将 `flag` 置为 -2，避免重复发送，并将当前人脸区域保存到 `faceMat`，同时本地保存一张 `face.jpg`file-crejcngjkpukkryjjpflje（用于调试或后续处理）。
- **未检测到人脸**：如果当前帧没有检测到人脸，则将 `ui->head` 标签移动回默认位置（如 `(100,60)`）file-crejcngjkpukkryjjpflje，隐藏信息显示的容器 `ui->widgetLb`，并将 `flag` 重置为 0file-crejcngjkpukkryjjpflje，准备下次检测。
- **图像显示**：无论是否检测到人脸，最后都要将摄像头帧显示在界面上。程序将 BGR 图像转换为 RGB 格式file-crejcngjkpukkryjjpflje，再创建 `QImage` 和 `QPixmap`，并将其设置到界面上的 `ui->videoLb` 标签file-crejcngjkpukkryjjpflje。这样用户界面就会实时显示摄像头画面。

## 网络通信机制

系统使用 `QTcpSocket` 实现客户端与服务器的 TCP 连接通信，机制如下：

- **自动重连机制**：构造函数中通过信号槽绑定实现：`msocket.connected` 信号连接到 `stop_connect` 槽file-crejcngjkpukkryjjpflje，`msocket.disconnected` 信号连接到 `start_connect` 槽file-crejcngjkpukkryjjpflje。这样在刚开始运行时，`mtimer` 定时器每 5 秒调用一次 `timer_connect()` 槽file-crejcngjkpukkryjjpflje，该槽函数中执行 `msocket.connectToHost("192.168.1.117",6000)`file-crejcngjkpukkryjjpflje尝试连接服务器。
  - 如果连接成功，`connected` 信号触发，`stop_connect()` 停止 `mtimer` 定时器，输出“成功连接服务器”消息file-crejcngjkpukkryjjpflje。
  - 如果连接断开，`disconnected` 信号触发，`start_connect()` 再次启动 `mtimer`，使得客户端每隔 5 秒重新尝试连接file-crejcngjkpukkryjjpflje。
- **数据发送**：当摄像头检测到人脸并准备好图像数据时，在 `timerEvent()` 中调用 `msocket.write(sendData)` 将封装好的图像和大小信息发送给服务器file-crejcngjkpukkryjjpflje。发送使用 `QDataStream` 打包，其中先写入数据长度再写入图像字节file-crejcngjkpukkryjjpflje，服务器在接收时可根据长度正确提取图像数据。注意设置版本号（`Qt_5_14`）以匹配双方 `QDataStream` 使用的协议file-crejcngjkpukkryjjpflje。
- **数据接收与解析**：`msocket.readyRead` 信号触发后调用 `recv_data()` 槽file-crejcngjkpukkryjjpflje。在该槽函数中，使用 `msocket.readAll()` 读取服务器发送过来的所有数据file-crejcngjkpukkryjjpflje。接收到的数据格式为 JSON 文本（例如 `{"employeeID": "...", "name": "...", "department": "...", "time": "..."}`）。程序通过 `QJsonDocument::fromJson()` 解析字节流为 JSON 文档，并转换为 `QJsonObject`file-crejcngjkpukkryjjpflje，从中提取 `"employeeID"`, `"name"`, `"department"`, `"time"` 四个字段的字符串值。最后将这些值分别显示到界面上的文本框 `numberEdit`, `nameEdit`, `departmentEdit`, `timeEdit`file-crejcngjkpukkryjjpflje。

## 图像显示与用户界面联动

系统界面将摄像头画面、检测结果和考勤信息动态结合：

- **摄像头实时显示**：界面中 `ui->videoLb` 是用于显示摄像头视频流的标签。在 `timerEvent()` 中，每捕获到一帧图像后，将其转换为 `QPixmap` 并设置到 `videoLb`，实现视频流实时显示file-crejcngjkpukkryjjpflje。
- **人脸位置标记**：在视频画面上，`ui->head` 作为一个小标签被用来标记检测到的人脸。程序通过 `ui->head->move(x,y)` 将其移动到当前检测到的人脸矩形的左上角坐标file-crejcngjkpukkryjjpflje，给用户直观提示人脸位置。如果没有检测到人脸，则将 `ui->head` 移动回界面预设的中心位置file-crejcngjkpukkryjjpflje。
- **考勤信息显示**：当收到服务器返回的考勤信息后，界面上会显示出具体内容。首先，`ui->widgetLb`（考勤信息容器）原本是隐藏的file-crejcngjkpukkryjjpflje，此时被调用 `ui->widgetLb->show()` 显示出来file-crejcngjkpukkryjjpflje。容器中有一个头像标签 `ui->headLb`，通过样式表将背景图设置为资源文件 `:/face.png` 并加上圆角样式file-crejcngjkpukkryjjpflje，模拟人脸头像显示。然后将解析出的员工编号、姓名、部门和时间填入 `numberEdit`, `nameEdit`, `departmentEdit`, `timeEdit` 四个文本框中file-crejcngjkpukkryjjpflje，供用户查看。通过这样的界面联动，用户可以同时看到视频中的人脸标记和服务器返回的员工考勤信息。

## 补充说明

- **开发板适配**：在嵌入式开发板上运行时，需要注意修改一些路径和版本设置：
  1. **摄像头设备路径**：`cap.open("/dev/video0")` 中的设备路径可能与开发板实际摄像头设备路径不同，需要根据板子的设备节点进行调整file-crejcngjkpukkryjjpflje。
  2. **级联文件路径**：`cascade.load()` 加载的 Haar 级联 XML 文件路径（如 `/opt/opencv4-pc/share/opencv4/haarcascades/haarcascade_frontalface_alt2.xml`）需要根据开发板上 OpenCV 安装的位置修改file-crejcngjkpukkryjjpflje。
  3. **数据流版本号**：在打包数据时使用了 `stream.setVersion(QDataStream::Qt_5_14)`file-crejcngjkpukkryjjpflje，确保这一版本号与目标开发板使用的 Qt 版本匹配，否则可能需要修改为相应版本。
- **其他注意事项**：人脸图像会被保存到 `face.jpg` 文件（当前目录）file-crejcngjkpukkryjjpflje。如果需要在界面中显示捕获到的实际人脸图像，可以进一步将其加载到 `ui->headLb`。总之，在实际部署时应根据硬件和环境灵活调整文件路径和软件版本，以保证各模块正常工作。