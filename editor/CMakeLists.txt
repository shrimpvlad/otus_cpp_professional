
cmake_minimum_required(VERSION 3.20)

project(editor)

set(BUILD_NUMBER 0 CACHE STRING "Build number")

add_executable(editor_cli main.cpp)
target_include_directories(editor_cli
    PUBLIC "${PROJECT_BINARY_DIR}"
)

set_target_properties(editor_cli PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(editor_cli PRIVATE
        /W4
    )
else ()
    target_compile_options(editor_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS editor_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH "${BUILD_NUMBER}")
set(CPACK_PACKAGE_CONTACT "example@example.com")
include(CPack)
