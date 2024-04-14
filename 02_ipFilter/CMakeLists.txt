cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "50" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(02_ipFilter VERSION ${PROJECT_VESRION})

set(ENV{PROJECT_NAME} "02_ipFilter")

configure_file(version.h.in version.h)

add_executable(ipFilter main.cpp)

add_library(ip_filter_lib ip_filter.cpp ip_filter.h)

add_executable(gtests gtests.cpp ip_filter.cpp)

target_include_directories(ip_filter_lib
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
)
target_link_libraries(ipFilter PRIVATE ip_filter_lib)

set_target_properties(ipFilter ip_filter_lib gtests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(ipFilter PRIVATE
        /W4
    )
    target_compile_options(ip_filter_lib PRIVATE
        /W4
    )
    target_compile_options(gtests PRIVATE
        /W4
    )
else ()
    target_compile_options(ipFilter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(ip_filter_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(gtests PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS ipFilter RUNTIME DESTINATION bin)

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

add_custom_command(TARGET ipFilter POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/ip_filter.tsv
    $<TARGET_FILE_DIR:ipFilter>
)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT "example@example.com")
include(CPack)

enable_testing()

