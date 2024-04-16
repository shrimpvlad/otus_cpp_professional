/*!
	\file
    \brief Файл содержит реализацию функции для печати условного IP-адреса.

    Функция реализована для различных входных параметров путем 
    использования механизма SFINAE, а на выходе дает строку.
*/
#include <string>
#include <tuple>
#include <vector>
#include <list>
#include <sstream>
#include <iostream>
#include <type_traits>

/*!
    \brief Реализация функции print_ip для целочисленных типов данных.
*/
template <typename T>
typename std::enable_if_t<std::is_integral_v<T>, std::string> print_ip(const T &data)
{
    auto cast = reinterpret_cast<const unsigned char *>(&data);
    auto bytes = sizeof(T);
    std::stringstream s;
    for (int i = bytes - 1; i >= 0; --i)
    {
        s << int(cast[i]);
        if (i)
        {
            s << '.';
        }
    }
    // s << '\n';
    return s.str();
}

/*!
    \brief Реализация функции print_ip для строк.
*/
template <typename T>
typename std::enable_if_t<std::is_same_v<T, std::string>, std::string> print_ip(const T &data)
{
    return data;
}

template <typename T>
struct is_container : std::false_type
{
};

template <typename T, typename Alloc>
struct is_container<std::vector<T, Alloc>> : std::true_type
{
};

template <typename T, typename Alloc>
struct is_container<std::list<T, Alloc>> : std::true_type
{
};

/*!
    \brief Реализация функции print_ip для векторов и списков.
*/
template <typename Container>
typename std::enable_if_t<is_container<Container>::value, std::string> 
print_ip(const Container &data)
{
    std::stringstream s;
    for (auto it = data.begin(); it != data.end(); ++it)
    {
        s << *it;
        if (it != --data.end())
        {
            s << '.';
        }
        
    }
    // s << '\n';
    return s.str();
}

template <typename T, typename... Args>
struct are_all_same : std::conjunction<std::is_same<T, Args>...>
{
};

/*!
    \brief Реализация функции print_ip для кортежей.
*/
template <typename... Args>
std::enable_if_t<are_all_same<Args...>::value, std::string>
print_ip(const std::tuple<Args...> &tuple)
{
    std::ostringstream result;
    std::apply([&result](const auto&... tupleArgs) {
                size_t index = 0;
                auto strElem = [&result, &index](const auto& x) {
                    if (index++ > 0) 
                        result << ".";
                    result << x;
                };

                (strElem(tupleArgs), ...);
            }, tuple
        );
    return result.str();
}

