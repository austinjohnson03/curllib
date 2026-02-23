cmake_minimum_required(VERSION 3.20)
project(curllib C)

set(CMAKE_C_STANDARD 11)

set(ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(ENABLE_PROGRAMS OFF CACHE BOOL "" FORCE)

add_subdirectory(libraries/mbedtls)


target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE
    mbedtls 
    mbedx509
    mbedcrypto
)
