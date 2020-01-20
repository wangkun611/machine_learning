add_executable(least_square least_square.cc least_square_unittest.cc)
add_dependencies(least_square gtest)
target_link_libraries(least_square gtest gtest_main)
add_test(NAME least_square COMMAND least_square)