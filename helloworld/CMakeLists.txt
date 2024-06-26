
cmake_minimum_required(VERSION 3.20)

project(helloworld)

set(BUILD_NUMBER 0 CACHE STRING "Build number")

configure_file(version.h.in version.h)


add_executable(helloworld_cli main.cpp)
add_executable(gtests gtests.cpp)
target_include_directories(helloworld_cli
    PUBLIC "${PROJECT_BINARY_DIR}"
)
target_include_directories(gtests
    PUBLIC "${PROJECT_BINARY_DIR}"
)

set_target_properties(helloworld_cli gtests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(helloworld_cli PRIVATE
        /W4
    )
    target_compile_options(gtests PRIVATE
        /W4
    )
else ()
    target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(gtests PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

target_link_libraries(gtests PRIVATE gtest gtest_main)

gtest_discover_tests(gtests)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH "${BUILD_NUMBER}")
set(CPACK_PACKAGE_CONTACT "example@example.com")

include(CPack)

enable_testing()
