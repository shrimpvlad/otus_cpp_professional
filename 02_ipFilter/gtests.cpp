#include <gtest/gtest.h>
#include "ip_filter.h"
#include <sstream>
TEST(IPFilter, MessageSort)
{
    auto sep = '\t';
    std::vector<Message> ip_pool;
    ip_pool.push_back(Message{"1.1.1.1\t2\t0", sep});
    ip_pool.push_back(Message{"1.2.1.1\t3333\t0.006", sep});
    ip_pool.push_back(Message{"1.10.1.1\t9.555\t0", sep});
    sortIp(ip_pool);
    std::stringstream in;
    for (const auto &ip : ip_pool)
    {
        in << ip << std::endl;
    }
    std::stringstream outExpected;
    outExpected << "1.10.1.1" << std::endl;
    outExpected << "1.2.1.1" << std::endl;
    outExpected << "1.1.1.1" << std::endl;
    ASSERT_EQ(in.str(), outExpected.str());
}