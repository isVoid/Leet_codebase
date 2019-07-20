#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include "dbg.hpp"
using namespace std;

struct ListNode;
struct TreeNode;
class Solution {
public:

    //TLE
    // bool backtracking(vector<int> &nums, int start) {
    //     if (start == nums.size() - 1) {
    //         return true;
    //     }

    //     int furthest = min(start + nums[start], (int)nums.size() - 1);

    //     // for (int i = start + 1; i <= furthest; i++) { from close to far
    //     for (int i = furthest; i > start; i--) { // from far to close
    //         if (backtracking(nums, i)) {
    //             return true;
    //         }
    //     }

    //     return false;
    // }

    //TLE
    // const int UNKNOWN = 0, GOOD = 1, BAD= 2;
    // bool backtracking_memo(vector<int> &nums, vector<int> &dp, int start) {
    //     if (dp[start] != UNKNOWN) {
    //         if (dp[start] == GOOD) {
    //             return true;
    //         }
    //         else {
    //             return false;
    //         }
    //     }

    //     int furthest = min(start + nums[start], (int)nums.size() - 1);
    //     for (int i = furthest; i > start; i--) {
    //         if (backtracking_memo(nums, dp, i)) {
    // v            dp[start] = GOOD;
    //             return true;
    //         }
    //     }

    //     dp[start] = BAD;
    //     return false;
    // }

    //580ms 10.95%
    //10MB 21.21%
    // const int GOOD = 1, BAD= 2;
    // bool bottomup_dp(vector<int> &nums) {
    //     vector<int> dp(nums.size(), BAD);
    //     dp[dp.size()-1] = GOOD;

    //     for (int i = dp.size()-1; i >= 0; i--) {
    //         int furthest = min(i + nums[i], (int)nums.size()-1);
    //         for (int j = i + 1; j <= furthest; j++) {
    //             if (dp[j] == GOOD) {
    //                 dp[i] = GOOD;
    //                 break;
    //             }
    //         }
    //     }

    //     return dp[0] == GOOD;
    // }

    //12ms 82.34%
    //9.7MB 84.31%
    bool greedy(vector<int> &nums) {
        int leftmost_good = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int furthest = min(i + nums[i], (int)nums.size() - 1);
            if (furthest >= leftmost_good) {
                leftmost_good = i;
            }
        }

        return leftmost_good == 0;
    }

    bool canJump(vector<int>& nums) {
        
        // return backtracking(nums, 0);

        //---
        // vector<int> memo(nums.size(), UNKNOWN);
        // memo[memo.size()-1] = GOOD;

        // return backtracking_memo(nums, memo, 0);

        //---
        // return bottomup_dp(nums);

        //---
        return greedy(nums);

    }
};

int main(int argc, char ** argv) {

    // vector<int> nums = {2, 3, 1, 1, 4};
    vector<int> nums = {3,2,1,0,4};
    cout << Solution().canJump(nums) << endl;

    return 0;
}