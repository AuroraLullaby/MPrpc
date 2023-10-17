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
# 三.protobuf  
  当数据序列化与反序列化时，通过rpcheader.proto在rpc框架中确定转发的消息类，这样client客户端和receiver服务器就可以统一使用protobuf实现序列化与反序列化，在rpc框架中服务器通过mprpcprovider.cc的NotifyService()外部接口使其调用，客户端中通过mprpcchannel.cc的CallMethod()接口实现调用。  
# 四.zookeeper  
框架中提供zookeeperutil.cc，在Start()函数中实现初始化，并通过global_watcher()函数实现初始化成功的返回。Create()和GetDate()分别完成绑定服务器ip和port,获取数据的任务。  
# 五.异步日志  
1.MPrpc框架中的Muduo网络库中高并发时，多个worker线程会争夺给_queue中写日志；  
2.另一个独立的“写日志线程”，会将_queue中的日志写入文件中；  
#. 编译    
1.可以在build中使用compile文件的方法，执行完成后在bin目录中运行
2.通过compile.sh文件实现一键编译。

