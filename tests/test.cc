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

class LeetCodeTester : public testing::TestWithParam<tuple<int, vector<vector<int>>>> {
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
                                std::make_tuple(0, vector<vector<int>>{ {0,1,5},
                                                                        {0,2,3},
                                                                        {0,3,2},
                                                                        {1,2,1},
                                                                        {1,4,2},
                                                                        {2,3,1},
                                                                        {3,4,3},
                                                                        {4,2,2}
                                                                        }),
                                std::make_tuple(0, vector<vector<int>>{ {0,4,100},
                                                                        {0,1,1},
                                                                        {0,5,1000},
                                                                        {1,2,2},
                                                                        {2,3,3},
                                                                        {3,4,4},
                                                                        {2,5,7}
                                                                        })
                            )
                         );
//vector<vector<int>>& times, int n, int k

TEST_P( LeetCodeTester, TestInputPattern1) {
  auto [ans, pattern] = GetParam();
//   auto list = myTest::Bellman(pattern,5,0);
//   for(auto n : list){
//     printf("%d \r\n",n);
//   }
    EXPECT_EQ(myTest::Bellman(pattern,5,0),myTest::Dijkstra(pattern,5,0));
//   auto list2 = myTest::Dijkstra(pattern,5,0);
//   for(auto n : list2){
//     printf("%d \r\n",n);
//   }
}