# cmake_minimum_required(VERSION 3.10)

# set(PATCH_VERSION "51" CACHE INTERNAL "Patch version")
# set(PROJECT_VESRION 0.0.${PATCH_VERSION})
# project(04_ipTemplates VERSION ${PROJECT_VESRION})

# set(ENV{PROJECT_NAME} "04_ipTemplates")
cmake_minimum_required(VERSION 3.10)

project(04_ipTemplates VERSION ${PROJECT_VERSION})

set(ENV{PROJECT_NAME} "04_ipTemplates")

# Определяем PATCH_VERSION из переменной окружения GITHUB_RUN_NUMBER
set(PATCH_VERSION "$ENV{GITHUB_RUN_NUMBER}" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

configure_file(version.h.in version.h)

add_executable(printIp main.cpp)

add_executable(gtests gtests.cpp)

set_target_properties(printIp gtests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(printIp PRIVATE
        /W4
    )
    target_compile_options(gtests PRIVATE
        /W4
    )
else ()
    target_compile_options(printIp PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(gtests PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS printIp RUNTIME DESTINATION bin)

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
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT "example@example.com")
include(CPack)

enable_testing()