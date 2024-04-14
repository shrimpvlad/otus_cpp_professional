#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <map>

template <class T>
struct cpp_11_allocator {
    using value_type = T;

    std::shared_ptr<void> pool;
    static constexpr std::size_t PoolSize = 1000;

    cpp_11_allocator () noexcept 
        : pool(::operator new (sizeof(uint8_t) * PoolSize), deleter())
    {
    }

    template <class U> cpp_11_allocator(const cpp_11_allocator <U>& a) noexcept {
        pool = a.pool;
    }

    cpp_11_allocator select_on_container_copy_construction() const
    { 
        std::cout << "cpp_11_allocator::select_on_container_copy_construction()" << std::endl;
        return cpp_11_allocator(); 
    }

    T* allocate (std::size_t n)
    {
        return static_cast<T*>(pool.get()); //dummy implementation
    }
    void deallocate (T* p, std::size_t n)
    {
        //implementation
    }

    template< class U >
    struct rebind
    {
        typedef cpp_11_allocator<U> other;
    };

    using propagate_on_container_copy_assignment = std::true_type;
    using propagate_on_container_move_assignment = std::true_type;
    using propagate_on_container_swap = std::true_type; //UB if std::false_type and a1 != a2;
};

template <class T, class U>
constexpr bool operator== (const cpp_11_allocator<T>& a1, const cpp_11_allocator<U>& a2) noexcept
{
    return a1.pool == a2.pool;
}

template <class T, class U>
constexpr bool operator!= (const cpp_11_allocator<T>& a1, const cpp_11_allocator<U>& a2) noexcept
{
    return a1.pool != a2.pool;
}