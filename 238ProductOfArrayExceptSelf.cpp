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

    //Runtime: 40 ms, faster than 86.43%
    // Memory Usage: 13.3 MB, less than 6.78%
    // vector<int> productExceptSelf(vector<int> nums) {
    //     int n = nums.size();
    //     #define B(i) nums[nums.size()-1-i]

    //     vector<int> front(n, 0);
    //     vector<int> back(n, 0);
    //     front[0] = 1;
    //     back[0] = 1;
    //     vector<int> ans(n, 0);

    //     for (int i = 0; i < nums.size()-1; i++) {
    //         front[i+1] = front[i] * nums[i];
    //         back[i+1] = back[i] * B(i);
    //     }

    //     for (int i = 0; i < nums.size(); i++) {
    //         ans[i] = front[i] * back[n-i-1];
    //     }

    //     printVector(ans);

    //     return ans;
    // }

    vector<int> productExceptSelf(vector<int> nums) {
        int n = nums.size();
        #define B(i) nums[nums.size()-1-i]

        vector<int> ans(n, 0);
        ans[0] = nums[0];
        int R = 1;

        for (int i = 1; i < nums.size()-1; i++) {
            ans[i] = nums[i] * ans[i-1];
        }

        printVector(ans);

        for (int i = nums.size()-1; i >= 1; i--) {
            ans[i] = R * ans[i-1];
            R *= nums[i];
        }
        ans[0] = R;
        printVector(ans);

        return ans;
    }
};

int main(int argc, char ** argv) {

    Solution().productExceptSelf({1, 2, 3, 4});
    // Solution().productExceptSelf({0, 0});

    return 0;
}