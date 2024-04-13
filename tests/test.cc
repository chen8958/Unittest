#include <gtest/gtest.h>
#include "codingfield.cc"
using namespace std;
// using namespace testing;

#define TEST_FUNC Solution::threeSum
class Solution {
public:
    static int threeSum(int nums)
    {
      return nums;
    }
};

class LeetCodeTester : public testing::TestWithParam<tuple<bool, int, vector<vector<int>>>> {
 public:
  void SetUp() override {  
  }
  void TearDown() override {
  }
};



INSTANTIATE_TEST_SUITE_P(TestInput1, LeetCodeTester,
                            // testing::Combine(
                            //     testing::Values(FALSE, TRUE),
                            //     testing::Values(2, 3),
                            //     testing::Values(
                            //         std::vector<std::vector<int>>{{0, 1}, {1, 0}},
                            //         std::vector<std::vector<int>>{{0, 1}, {1, 2}}
                            //         )
                            //     )
                            testing::Values(
                                // std::make_tuple(FALSE, 2, std::vector<std::vector<int>>{{0, 1}, {1, 0}}),
                                // std::make_tuple(TRUE, 3, std::vector<std::vector<int>>{{0, 1}, {1, 2}}),
                                // std::make_tuple(TRUE, 1, std::vector<std::vector<int>>{}),
                                // std::make_tuple(FALSE, 5, std::vector<std::vector<int>>{{0, 1},{0, 2},{2, 3},{3, 4},{4, 2}}),
                                // std::make_tuple(TRUE, 5, std::vector<std::vector<int>>{{0, 1},{0, 2},{2, 3},{3, 4},{1, 4}}),
                                // std::make_tuple(TRUE, 6, std::vector<std::vector<int>>{{0, 1},{0, 2},{2, 3},{3, 4},{3, 5},{5, 1}})
                                std::make_tuple(TRUE, 4, std::vector<std::vector<int>>{{0, 1},{1, 2},{2, 3},{0, 3}})
                            )
                         );


TEST_P( LeetCodeTester, TestInputPattern1) {
  auto [input, n, output] = GetParam();
  EXPECT_EQ(input, myTest::canFinish(n, output));
}