#include "ip_filter.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    try
    {
        std::string fileName = "ip_filter.tsv";
        auto sep = '\t';
        std::vector<Message> ip_pool;
        fileReader(fileName, ip_pool, sep);
        
        sortIp(ip_pool);
        for (const auto &ip : ip_pool)
        {
            // auto i = ip.getIp();
            std::cout << ip << std::endl;
        }
        // std::cout << "-----------" << std::endl;
        for (const auto &ip : ip_pool) {
            if (ip.getIp()[0] == 1) {
                std::cout << ip << std::endl;
            }
        }
        // std::cout << "-----------" << std::endl;
        for (const auto &ip : ip_pool) {
            if (ip.getIp()[0] == 46 && ip.getIp()[1] == 70) {
                std::cout << ip << std::endl;
            }
        }
        // std::cout << "-----------" << std::endl;
        for (const auto &ip : ip_pool) {
            if (ip.getIp()[0] == 46 || ip.getIp()[1] == 46 || ip.getIp()[2] == 46 || ip.getIp()[3] == 46) {
                std::cout << ip << std::endl;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
