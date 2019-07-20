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

    //Sliced DP
    //Under circular condition, one cannot both rob first and last
    //Case 1: rob first
    //Case 2: do not rob first

    //4ms 97.41%
    //8.7MB 58.46%
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> case1, case2;
        case1.reserve(n);
        case2.reserve(n);

        //Case 1
        case1.push_back(nums[0]);
        case1.push_back(nums[0]); //Cannot rob this

        //Case 2
        case2.push_back(0); //Cannot rob this
        case2.push_back(nums[1]);

        for (int i = 2; i <= n-1; i++) {
            //For the last, case 1 (rob first) cannot rob this.
            //Case 2 (do not rob first) can rob this
            if (i == n-1) {
                case1.push_back(case1[i-1]);
                case2.push_back(max(nums[i] + case2[i-2], case2[i-1]));
            }
            else {
                case1.push_back(max(nums[i] + case1[i-2], case1[i-1]));
                case2.push_back(max(nums[i] + case2[i-2], case2[i-1]));
            }
        }

        // printVector(case1);
        // printVector(case2);

        return max(case1[n-1], case2[n-1]);

    }
};

int main(int argc, char ** argv) {

    // vector<int> n = {2, 3, 2};
    vector<int> n = {1, 2, 3, 1};
    
    cout << Solution().rob(n) << endl;

    return 0;
}