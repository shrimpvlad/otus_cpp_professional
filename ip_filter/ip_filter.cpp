#include "ip_filter.h"

Message::Message(const std::string &str, char d)
{
    auto ipAndExtraInfo = split(str, d);
    auto stringIp = ipAndExtraInfo[0];
    extraInfo.push_back(ipAndExtraInfo[1]);
    extraInfo.push_back(ipAndExtraInfo[2]);
    auto parsedIp = split(stringIp, '.');
    for (auto& part : parsedIp) {
        ip.push_back(std::stoi(part));
    }
}

std::vector<std::string> Message::split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    r.push_back(str.substr(start));
    return r;
}

std::vector<int> Message::getIp() const
{
    return ip;
}

std::ostream &operator<<(std::ostream &os, const Message &message)
{
    auto ip = message.getIp();
    return os << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3];
}

void sortIp(std::vector<Message> &ip_pool)
{
    std::sort(ip_pool.begin(), ip_pool.end(), [](const Message &mes1, const Message &mes2)
              { return mes1.getIp() > mes2.getIp(); });
}

void fileReader(const std::string& fileName, std::vector<Message>& ip_pool, 
                char sep) 
{
    std::string line;
    std::ifstream file(fileName); // окрываем файл для чтения
    if (file.is_open())
    {

        while (std::getline(file, line))
        {
            ip_pool.push_back(Message{line, sep});
        }
    }
    else {
        std::runtime_error("Unable to open file " + fileName);
    }
    file.close();
}