#include <iostream>
#include <windows.h>

bool checkRegistryKeyExists(const char* keyPath) {
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, keyPath, 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
        return false;
    }
    RegCloseKey(hKey);
    return true;
}

int main() {
    if (checkRegistryKeyExists("SOFTWARE\\Microsoft\\Microsoft SQL Server")) {
        std::cout << "本机存在 Microsoft SQL Server 数据库" << std::endl;
    } else if (checkRegistryKeyExists("SOFTWARE\\PostgreSQL")) {
        std::cout << "本机存在 PostgreSQL 数据库" << std::endl;
    } else if (checkRegistryKeyExists("SOFTWARE\\MySQL AB\\MySQL Server")) {
        std::cout << "本机存在 MySQL 数据库" << std::endl;
    } else if (checkRegistryKeyExists("SOFTWARE\\MongoDB\\Server")) {
        std::cout << "本机存在 MongoDB 数据库" << std::endl;
    } else if (checkRegistryKeyExists("SOFTWARE\\ORACLE")) {
        std::cout << "本机存在 Oracle 数据库" << std::endl;
    } else {
        std::cout << "本机没有安装常见的数据库" << std::endl;
    }
    
    return 0;
}
