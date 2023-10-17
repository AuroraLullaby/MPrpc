#pragma once

#include "mprpcconfig.h"
#include "mprpcchannel.h"
#include "mprpccontroller.h"

// mprpc框架的基础类，负责框架的一些初始化操作
class MprpcApplication
{
public:
    static void Init(int argc, char **argv);
    static MprpcApplication& GetInstance(); //获取实例的方法
    static MprpcConfig& GetConfig();  // 返回引用，用于rpcprovider.cc的Run()函数的配置文件
private:
    static MprpcConfig m_config;

    MprpcApplication(){}
    MprpcApplication(const MprpcApplication&) = delete; //把与拷贝构造相关的都删掉 
    MprpcApplication(MprpcApplication&&) = delete;
};