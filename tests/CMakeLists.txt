add_executable(
        tests_heap
        tests_heap.cpp
)

target_include_directories(tests_heap PRIVATE ${PROJECT_SOURCE_DIR} )

target_link_libraries(
        tests_heap
        gtest_main
        gtest
        pthread
)

include(GoogleTest)

gtest_discover_tests(tests_heap)
