
add_executable(
  test
  test.cc
)
target_link_libraries(
  test
  GTest::gtest_main
)

gtest_discover_tests(hello_test)