#include <gtest/gtest.h>
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

class LeetCodeTester : public testing::TestWithParam<tuple<int,int>> {
 public:
  void SetUp() override {  
  }
  void TearDown() override {
  }
};

INSTANTIATE_TEST_SUITE_P(TestInput1, LeetCodeTester,
                         testing::Combine(testing::Values(10), testing::Values(10))
                         );


TEST_P( LeetCodeTester, TestInputPattern1) {
  auto [input ,output] = GetParam();
  EXPECT_EQ(output, TEST_FUNC(input));
}