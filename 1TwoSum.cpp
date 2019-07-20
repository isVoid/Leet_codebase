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
    //8ms 96.57%
    //10.1MB 36.22%
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                ans[0] = i;
                ans[1] = m[target-nums[i]];
                return ans;
            }
            m.insert(pair<int, int>(nums[i], i));
        }

        return ans;
    }
};

int main(int argc, char ** argv) {

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    printVector(Solution().twoSum(nums, target));

    return 0;
}