#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <algorithm>
#include <stdexcept>

class Message
{
    std::vector<int> ip;
    std::vector<std::string> extraInfo;
    std::vector<std::string> split(const std::string &str, char d);

public:
    Message(const std::string &str, char d);
    std::vector<int> getIp() const;
    friend void sortIp(std::vector<Message> &ip_pool);
    friend std::ostream &operator<<(std::ostream &os, const Message &message);
};

void fileReader(const std::string& fileName, std::vector<Message>& ip_pool, 
                char sep);

