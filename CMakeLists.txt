cmake_minimum_required(VERSION 3.22)
project(heap_seance)

set(CMAKE_CXX_STANDARD 14)

add_executable(heap_demo main.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.12.x
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(tests)
