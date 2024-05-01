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

class LeetCodeTester : public testing::TestWithParam<tuple<int ,vector<vector<int>>, int, int>> {
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

                                std::make_tuple(3, std::vector<std::vector<int>>{{1,2,1},{2,3,2},{1,3,4}}, 3, 1)
                            )
                         );
//vector<vector<int>>& times, int n, int k

TEST_P( LeetCodeTester, TestInputPattern1) {
  auto [ans, times, n, k] = GetParam();
  EXPECT_EQ(ans, myTest::networkDelayTime(times, n, k));
}