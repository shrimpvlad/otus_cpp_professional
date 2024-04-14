cmake_minimum_required(VERSION 3.8)
set(PATCH_VERSION "30" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(ip_filter)

set(ENV{PROJECT_NAME} "ip_filter")

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

# Устанавливаем опции компилятора
if (MSVC)
    target_compile_options(ipFilter PRIVATE
        /W4
    )
    target_compile_options(ip_filter_lib PRIVATE
        /W4
    )
    # target_compile_options(gtests PRIVATE
    #     /W4
    # )
else ()
    target_compile_options(ipFilter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(ip_filter_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    # target_compile_options(gtests PRIVATE
    #     -Wall -Wextra -pedantic -Werror
    # )
endif()

# Устанавливаем цель установки для исполняемого файла printIp
install(TARGETS ipFilter RUNTIME DESTINATION bin)

# Добавляем внешний проект Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Подключаем Google Test
include(GoogleTest)

# Линкуем исполняемый файл gtests с библиотеками Google Test и gtest_main
target_link_libraries(gtests PRIVATE gtest gtest_main)

# Включаем файлы с тестами в цели тестирования CTest
gtest_discover_tests(gtests)

add_custom_command(TARGET ipFilter POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/ip_filter.tsv
    $<TARGET_FILE_DIR:ipFilter>
)

# Настраиваем упаковщик для создания deb-пакета
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_CONTACT "example@example.com")
include(CPack)

enable_testing()


#############################################################

# cmake_minimum_required(VERSION 3.10)

# set(PATCH_VERSION "30" CACHE INTERNAL "Patch version")
# set(PROJECT_VESRION 0.0.${PATCH_VERSION})

# project(01_helloWorld VERSION ${PROJECT_VESRION})

# set(ENV{PROJECT_NAME} "01_helloWorld")

# configure_file(version.h.in version.h)

# add_executable(helloworld_cli main.cpp)
# add_library(helloworld lib.cpp)

# target_include_directories(helloworld
#     PRIVATE "${CMAKE_BINARY_DIR}"
# )

# target_link_libraries(helloworld_cli PRIVATE
#     helloworld
# )

# set_target_properties(helloworld_cli helloworld PROPERTIES
#     CXX_STANDARD 17
#     CXX_STANDARD_REQUIRED ON
# )

# if (MSVC)
#     target_compile_options(helloworld_cli PRIVATE
#         /W4
#     )
#     target_compile_options(helloworld PRIVATE
#         /W4
#     )
# else ()
#     target_compile_options(helloworld_cli PRIVATE
#         -Wall -Wextra -pedantic -Werror
#     )
#     target_compile_options(helloworld PRIVATE
#         -Wall -Wextra -pedantic -Werror
#     )
# endif()

# install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

# set(CPACK_GENERATOR DEB)

# set(CPACK_PACKAGE_NAME ${PROJECT_NAME})

# set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
# set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
# set(CPACK_PACKAGE_CONTACT example@example.com)

# include(CPack)
# enable_testing()

# add_subdirectory(GTests)

# target_include_directories(tests PUBLIC ${CMAKE_BINARY_DIR})
