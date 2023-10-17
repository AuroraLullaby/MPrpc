# 一.项目依赖：  
1.muduo网络库 (https://github.com/chenshuo/muduo)  
2.protobuf 数据序列化与反序列化 (https://github.com/protocolbuffers/protobuf)  
3.zookeeper 分布式协调服务 (https://github.com/apache/zookeeper)  
4.CMake 集成编译环境  
5.异步日志读取  
# 二.rpc框架
## server端：
1.填写proto文件，其中package代表命名空间、message代表类，service代表服务对象,通过protobuf生成C++ Service基类，服务提供方要实现protobuf生成接口。  
2.继承后重写基类虚函数，重写的内容为从request中得到参数，处理本地业务，将返回值打包到response中，执行回调函数done把response序列化并发送至远端。
3.要把服务加入Service，实参为子类的对象，形参为父类的指针，实现rpc框架接受不同的服务。
## client端：
对客户端实现简单接口API调用  
1.需用协商一致的protobuf文件，protobuf生成 XX_stub的类供用户端使用，这个类通过多态调用到服务端。
2.调用 XX_stub的方法(对应服务端发布的方法)，在mprpcchannel函数中调用CallMethod，将客户端需要实现的服务发送。  
