#include <iostream>
#include <bit>
#include <unordered_map>

template <class A, class B>
struct std::hash<std::pair<A, B>>
{
    size_t operator()(const std::pair<A, B> &p) const
    {
        return std::rotl(std::hash<A>{}(p.first), 1) ^
               std::hash<B>{}(p.second);
    }
};

// Шаблонный класс для матрицы
template<typename T, T DefaultValue>
class Matrix {
public:
    class Proxy {
    public:
        Proxy(Matrix& matrix, int row, int col) : matrix_(matrix), row_(row), col_(col) {}

        // Присвоение значения ячейке
        Proxy& operator=(const T& value) {
            if (value == DefaultValue) {
                matrix_.cells_.erase({row_, col_});
            } else {
                matrix_.cells_[{row_, col_}] = value;
            }
            return *this;
        }

        // Чтение значения ячейки
        operator T() const {
            auto it = matrix_.cells_.find({row_, col_});
            if (it != matrix_.cells_.end()) {
                return it->second;
            }
            return DefaultValue;
        }

    private:
        Matrix& matrix_;
        int row_;
        int col_;
    };

    // класс строк
    class Row {
    public:
        Row(Matrix& matrix, int row) : matrix_(matrix), row_(row) {}

        Proxy operator[](int col) {
            return Proxy(matrix_, row_, col);
        }

    private:
        Matrix& matrix_;
        int row_;
    };

    Row operator[](int row) {
        return Row(*this, row);
    }

    size_t size() const {
        return cells_.size();
    }
    
    auto begin() {
        return cells_.begin();
    }
    auto end() {
        return cells_.end();
    }


private:
    std::unordered_map<std::pair<int, int>, T> cells_;
};


