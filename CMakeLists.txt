
cmake_minimum_required(VERSION 3.10)

project(MiniQemu VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(miniqemu ${SOURCES})

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(miniqemu PRIVATE -Wall -Wextra -Wpedantic)
endif()

# (Optional) Install rules
# install(TARGETS miniqemu DESTINATION bin)
