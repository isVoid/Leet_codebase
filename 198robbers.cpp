#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include "dbg.hpp"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // Dynamic Programming
    // dp[i] = max(heval[i] + dp[i-2], dp[i-1])
    // The value achieved at current 
    // time step i can come from two different
    // decision:
    // 1. The current house is robbed, then the 
    // previous house cannot be roobed, the total
    // is heval[i] + dp[i-2]
    // 2. The current house is not robbed, then 
    // the total value is the same as the previous
    // step. We take the max of these decisions.
    // Initial 2 steps: choose the max house value
    // to rob from.

    // Use extra array, O(n);O(n)
    // 4ms 100%
    // int rob(vector<int>& nums) {
    //     if (nums.size() == 0)
    //         return 0;
    //     else if (nums.size() == 1) 
    //         return nums[0];
    //     else if (nums.size() == 2)
    //         return max(nums[0], nums[1]);

    //     // Initialize
    //     int dp[nums.size()];
    //     dp[0] = nums[0];
    //     dp[1] = max(nums[0], nums[1]);

    //     for (int i = 2; i < nums.size(); i++) {
    //         dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
    //     }

    //     return dp[nums.size() - 1];
    // }

    // Use No Extra Array, O(n);O(1)
    // 8ms 17.87%
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1) 
            return nums[0];
        else if (nums.size() == 2)
            return max(nums[0], nums[1]);

        int dp_i_1 = max(nums[0], nums[1]), dp_i_2 = nums[0], dp;
        for (int i = 2; i < nums.size(); i++) {
            dp = max(nums[i] + dp_i_2, dp_i_1);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp;
        }
        return dp;
    }
};

int main() {

    int houses[] = {2, 7, 9, 3, 1};
    // int houses[] = {1};
    // int houses[] = {};
    // int houses[] = {2, 1, 1, 2};
    auto v = vectorFromArray(houses, sizeof(houses));

    Solution s;
    cout << s.rob(v) << endl;

    return 0;
}