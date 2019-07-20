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

    //4ms 85.58%
    //8.7MB 63.60%
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1l;

        for (int i = 0; i < dp.size(); i++) {
            for (int n : nums) {
                if (n <= i) {
                    dp[i] += dp[i-n];
                }
            }
        }
        printVector(dp);
        return dp[target];
    }
};

int main(int argc, char ** argv) {

    vector<int> nums = {1, 2, 3};
    int target = 4;

    cout << Solution().combinationSum4(nums, target) << endl;

    return 0;
}