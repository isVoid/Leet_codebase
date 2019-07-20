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
    // //8ms 31.76%
    // //8.7MB 48.01%
    // //O(n^2)
    // int wiggleMaxLength(vector<int>& nums) {
    //     if (nums.size() == 0) return 0;

    //     vector<int> dp_gtr(nums.size(), 0);
    //     vector<int> dp_les(nums.size(), 0);

    //     dp_gtr[nums.size()-1] = 1;
    //     dp_les[nums.size()-1] = 1;

    //     int ans = 1;

    //     for (int i = nums.size()-2; i >= 0; i--) {
    //         int gtr = 1, les = 1;
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             if (nums[i] > nums[j]) {
    //                 gtr = max(gtr, dp_les[j] + 1);
    //             }
    //             if (nums[i] < nums[j]) {
    //                 les = max(les, dp_gtr[j] + 1);
    //             }
    //         }
    //         ans = max(max(ans, gtr), les);
    //         dp_gtr[i] = gtr;
    //         dp_les[i] = les;
    //     }

    //     printVector(dp_gtr);
    //     printVector(dp_les);

    //     return ans;
    // }

    //4ms 86.10%
    //8.7MB 26.59%
    int wiggleMaxLength(vector<int>& nums) {
        
        if (nums.size() == 0) return 0;

        vector<int> up(nums.size(), 0);
        vector<int> down(nums.size(), 0);

        up[0] = 1;
        down[0] = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            else if (nums[i] < nums[i-1]) {
                up[i] = up[i-1];
                down[i] = up[i-1] + 1;
            }
            else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }

        printVector(up);
        printVector(down);
        return max(up[nums.size()-1], down[nums.size()-1]);
    }
};

int main(int argc, char ** argv) {

    // vector<int> dp = {1,17,5,10,13,15,10,5,16,8};
    // vector<int> dp = {1,7,4,9,2,5};
    vector<int> dp = {1, 2, 3, 4};
    // vector<int> dp = {1};
    // vector<int> dp = {};

    cout << Solution().wiggleMaxLength(dp) << endl;

    return 0;
}