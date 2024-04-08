cmake_minimum_required(VERSION 3.22)
project(String_Implement)

set(CMAKE_CXX_STANDARD 20)

add_executable(String_Implement main.cpp
        String.cpp)

#target_compile_options(String_Implement PRIVATE -Wall -Wextra -pedantic -std=c++20)
target_compile_options(String_Implement PRIVATE -Wall -Wextra -pedantic -fsanitize=address -fno-omit-frame-pointer)
target_link_options(String_Implement PRIVATE -fsanitize=address)
