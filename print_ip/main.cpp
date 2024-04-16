/*!
	\file
    \brief Файл содержит прикладной код с необходимыми вызовами
*/
#include "ipParser.hpp"

int main()
{
    std::cout << print_ip(int8_t{-1}) << std::endl;
    std::cout << print_ip(int16_t{0}) << std::endl;
    std::cout << print_ip(int32_t{2130706433}) << std::endl;
    std::cout << print_ip(int64_t{8875824491850138409}) << std::endl;
    std::cout << print_ip(std::string{"Hello, World!"}) << std::endl;
    std::cout << print_ip(std::vector<int>{100, 200, 300, 400}) << std::endl;
    std::cout << print_ip(std::list<short>{400, 300, 200, 100}) << std::endl;
    std::cout << print_ip(std::make_tuple(123, 456, 789, 0)) << std::endl;
    // std::cout << print_ip(std::make_tuple(1, "2", 3) << std::endl; // compilation error
}