文件内容说明：
#AttendenceServer里面为服务器文件																	
#build-faceAttendence-Desktop_Qt_5_14_2_GCC_64bit-Debug为QT下生成的一些中间文件
#faceAttendence为客服端文件

主要工作：
1.优化OpenCV的DNN和Haar级联算法实现高精度实时人脸检测与跨场景适配
OpenCV的DNN（深度神经网络）模块：DNN是一种基于深度学习的人脸检测方法，通常比传统的Haar级联算法更准确，尤其在复杂光照、姿态变化、遮挡等跨场景条件下表现更好。通过优化DNN算法，可以提高人脸检测的准确性和鲁棒性，减少误检和漏检，使其能够适应各种实际考勤环境。
Haar级联算法：这是一种基于特征的机器学习方法，在计算资源有限的情况下，它可能提供较快的检测速度。优化Haar级联算法可能包括调整参数、选择更合适的分类器或结合其他技术来提高其在特定场景下的性能。
高精度实时人脸检测与跨场景适配：这意味着系统不仅能准确识别出人脸，而且能在不同环境（如光线明暗变化、背景复杂等）和不同用户状态（如戴眼镜、微表情变化等）下保持高性能，并能以足够快的速度进行处理，以满足实时考勤的需求。

2.服务端采用SQLite实现毫秒级人脸特征检索与动态阈值管理
SQLite：这是一种轻量级的、嵌入式关系型数据库，不需要独立的服务器进程，可以直接将数据存储在文件中。在嵌入式系统中，其占用资源少、易于集成和部署的特点使其成为理想选择。
毫秒级人脸特征检索：在人脸识别系统中，注册的人脸会经过特征提取，生成一系列数字向量（人脸特征）。当用户打卡时，系统会提取当前人脸的特征，并与数据库中存储的所有人脸特征进行比对。毫秒级的检索速度表示系统能够非常迅速地在大量人脸数据中找到匹配项，这对于保证考勤系统的响应速度和用户体验至关重要。
动态阈值管理：人脸识别的比对结果通常是一个相似度分数。系统会设定一个阈值，当相似度分数高于该阈值时，认为识别成功。动态阈值管理意味着这个阈值不是固定的，而是可以根据环境条件、识别需求、系统负载等因素自动调整。例如，在光线较差的环境下，可以适当降低阈值以提高召回率；在对安全性要求较高时，可以提高阈值以降低误识率。这种灵活性有助于提高系统的适应性和性能。

3.结合嵌入式Linux系统裁剪库依赖、优化资源监控，完成低功耗、高稳定的工业级考勤系统部署
嵌入式Linux系统裁剪库依赖：嵌入式系统通常资源有限（CPU、内存、存储空间）。“裁剪库依赖”是指移除操作系统和应用程序中非必需的软件库和组件，只保留系统运行和功能实现所必需的部分。这样做可以显著减小系统体积，降低内存占用，减少启动时间，并降低功耗。
优化资源监控：指实时监测和管理嵌入式设备上的CPU利用率、内存使用、存储空间、网络带宽等系统资源。通过优化资源监控，可以确保系统在长时间运行中保持稳定，避免资源耗尽导致系统崩溃或性能下降，及时发现并解决潜在问题。
低功耗：对于嵌入式设备而言，功耗是关键指标。通过软件优化（如算法效率提升、库裁剪）和硬件选择，使系统在运行过程中消耗的电能尽可能少，从而延长设备寿命，降低运行成本，并可能支持电池供电。
高稳定：工业级系统对稳定性要求极高，意味着系统能够长时间不间断地可靠运行，不受环境干扰或软件bug的影响。这通过严格的测试、错误处理机制、资源管理和代码质量来实现。
工业级考勤系统部署：表示该系统不仅是一个概念验证或实验性项目，而是达到了工业应用标准，具备在恶劣或复杂环境中稳定、可靠、高效运行的能力，能够满足企业或机构对考勤管理的严格要求。
