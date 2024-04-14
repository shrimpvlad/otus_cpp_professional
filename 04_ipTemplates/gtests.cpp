/*!
	\file
    \brief Файл содержащий google test для функции печати IP адресов 
    с различными входными данными
*/

#include <gtest/gtest.h>
#include "ipParser.hpp"

/*!
    \brief Тестирование функции print_ip для целочисленных типов данных.
 
    Этот тест проверяет корректность вывода IP-адресов для целочисленных типов данных.
 */
TEST(PrintIP, Int) {
    std::string expectedResult1 = "255";
    std::string expectedResult2 = "0.0";
    std::string expectedResult3 = "127.0.0.1";
    std::string expectedResult4 = "123.45.67.89.101.112.131.41";
    ASSERT_EQ(print_ip(int8_t{-1}), expectedResult1);
    ASSERT_EQ(print_ip(int16_t{0}), expectedResult2);
    ASSERT_EQ(print_ip(int32_t{2130706433}), expectedResult3);
    ASSERT_EQ(print_ip(int64_t{8875824491850138409}), expectedResult4);
}

/*!
    \brief Тестирование функции print_ip для строк.
 
    Этот тест проверяет корректность вывода IP-адресов для строк.
 */
TEST(PrintIP, String) {
    std::string inputString = "Hello, World!";
    std::string expectedResult = "Hello, World!";
    ASSERT_EQ(print_ip(inputString), expectedResult);
}

/*!
    \brief Тестирование функции print_ip для вектора.
 
    Этот тест проверяет корректность вывода IP-адресов для вектора.
 */
TEST(PrintIP, Vector) {
    std::vector<int> inputVector = {100, 200, 300, 400};
    std::string expectedResult = "100.200.300.400";
    ASSERT_EQ(print_ip(inputVector), expectedResult);
}

/*!
    \brief Тестирование функции print_ip для списка.
 
    Этот тест проверяет корректность вывода IP-адресов для списка.
 */
TEST(PrintIP, List) {
    std::list<int> inputList = {400, 300, 200, 100};
    std::string expectedResult = "400.300.200.100";
    ASSERT_EQ(print_ip(inputList), expectedResult);
}

/*!
    \brief Тестирование функции print_ip для кортежа.
 
    Этот тест проверяет корректность вывода IP-адресов для кортежа.
 */
TEST(PrintIP, Tuple) {
    auto inputTuple1 = std::make_tuple(123, 456, 789, 0);
    auto inputTuple2 = std::make_tuple("111", "221", "456", "999");
    std::string expectedResult1 = "123.456.789.0";
    std::string expectedResult2 = "111.221.456.999";
    ASSERT_EQ(print_ip(inputTuple1), expectedResult1);
    ASSERT_EQ(print_ip(inputTuple2), expectedResult2);
}
