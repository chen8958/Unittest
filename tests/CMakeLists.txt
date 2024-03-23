
add_executable(
  test_exmaple
  test.cc
)
target_link_libraries(
  test_exmaple
  GTest::gtest_main
)
gtest_discover_tests(test_exmaple)