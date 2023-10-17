#aux_source_directory(. SRC_LIST)
set(SRC_LIST 
    mprpcapplication.cc 
    mprpcconfig.cc 
    rpcheader.pb.cc 
    mprpcprovider.cc 
    mprpcchannel.cc
    mprpccontroller.cc
    logger.cc
    zookeeperutil.cc)
add_library(mprpc ${SRC_LIST})  #加SHARED为动态库，但muduo编译为静态库.a,所以也编译为静态库，当然，也可以把muduo编译为动态库.so
target_link_libraries(mprpc muduo_net muduo_base pthread zookeeper_mt) # st为单线程版本，mt为多线程版本