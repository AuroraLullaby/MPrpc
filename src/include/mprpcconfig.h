#pragma once

#include <unordered_map>
#include <string>

// rpcserverip   rpcserverport    zookeeperip   zookeeperport
// 框架读取配置文件类,属于IO操作，不需要重复配置，放入unordered_map键值对中就可以
class MprpcConfig
{
public:
    // 负责解析加载配置文件
    void LoadConfigFile(const char *config_file);
    // 查询配置项信息
    std::string Load(const std::string &key);
private:
    std::unordered_map<std::string, std::string> m_configMap; // map容器不是线程安全，但框架只加载一次就，不需要考虑是否线程安全
    // 去掉字符串前后的空格
    void Trim(std::string &src_buf);
};