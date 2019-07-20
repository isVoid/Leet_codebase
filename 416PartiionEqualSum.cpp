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

    // void addToSet(set< pair<int, int> > *s, pair<int, int> p) {
    //     if (p.second < p.first) {
    //         p = pair<int, int>(p.second, p.first);
    //     }
    //     (*s).insert(p);
    // }

    // //1604ms 5.05%
    // //292.9MB 5.01%
    // bool canPartition(vector<int>& nums) {
    //     if (nums.size() < 2) return false;
    //     if (nums.size() == 2 && nums[0] == nums[1]) return true;

    //     set < pair<int, int> > *s = new set< pair<int, int> >;

    //     int sum = 0;
    //     for (int i : nums) sum += i;
    //     int half_sum = sum / 2;

    //     addToSet(s, pair<int, int>(nums[0], nums[1]));

    //     for (int i = 2; i < nums.size(); i++) {
    //         int n = nums[i];
    //         set < pair<int, int> > *s_prime = new set< pair<int, int> >;

    //         for (set< pair<int, int> >::iterator it = (*s).begin(); it != (*s).end(); it++) {
    //             if ((*it).first + n <= half_sum)
    //                 addToSet(s_prime, pair<int, int>((*it).first + n, (*it).second));
    //             if ((*it).second + n <= half_sum)
    //                 addToSet(s_prime, pair<int, int>((*it).first, (*it).second + n));
    //         }

    //         int prev_sum = (*(*s).begin()).first + (*(*s).begin()).second;
    //         if (prev_sum <= half_sum)
    //             addToSet(s_prime, pair<int, int>(prev_sum, n));

    //         (*s).clear();
    //         delete s;
    //         s = s_prime;
    //     }

    //     for (set< pair<int, int> >::iterator it = (*s).begin(); it != (*s).end(); it++) {
    //         // cout << "Partition Sum: " << (*it).first << " " << (*it).second << endl;
    //         if ((*it).first == (*it).second) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    //388ms 6.11%
    //10.7MB 24.59%
    // bool canPartition(vector<int>& nums) {

    //     int n = nums.size();
    //     int sum = 0;
    //     for (auto i : nums) sum += i;
    //     if (sum % 2 != 0) return false;
    //     int half_sum = sum / 2;

    //     for (auto i : nums)
    //         if (half_sum < i)
    //             return false;

    //     vector< vector< bool> > dp(n+1, vector<bool>(half_sum + 1, false));

    //     for (int i = 0; i <= n; i++) {
    //         for (int j = 0; j <= half_sum; j++) {
                
    //             if (i == 0 && j == 0) 
    //                 dp[i][j] = true;

    //             else if (i == 0)
    //                 dp[i][j] = false;

    //             else if (j == 0)
    //                 dp[i][j] = true;

    //             else {
    //                 dp[i][j] = dp[i-1][j];
    //                 if (j >= nums[i-1])
    //                     dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];
                    
    //                 // if (i == 4 && j == 6)
    //                 //     printMatrix(dp);
    //             }
    //         }   
    //     }

    //     // printMatrix(dp);

    //     return dp[n][half_sum];
    // }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n : nums) sum += n;
        if (sum & 1) return false;
        sort(nums.begin(), nums.end(), greater<int>());
        return helper(nums, 0, sum / 2);
    }

    bool helper(vector<int>& nums, int index, int target) {
        if (target == 0) return true;
        if (index >= nums.size() || target < 0) return false;

        for (int i = index; i < nums.size(); i++) {
            if (helper(nums, i+1, target - nums[index])) {
                return true;
            }
        }
        
        return false;
    }
};

int main(int argc, char ** argv) {

    // vector<int> nums = {1, 2, 4, 2, 5};
    // vector<int> nums = {1, 2, 3, 5};
    // vector<int> nums = {1, 5, 11, 5};
    // vector<int> nums = {};
    // vector<int> nums = {1};
    // vector<int> nums = {1, 2};
    // vector<int> nums = {1, 1};
    // vector<int> nums = {97,100,88,49,43,55,2,62,72,13,60,36,67,64,13,39,66,6,26,45,46,75,28,66,71,75,91,33,64,54,3,76,76,35,49,6,63,11,80,86,73,95,60,58,61,42,52,27,73,51,58,38,28,62,84,55,90,40,52,96,55,32,52,63,44,90,14,68,50,32,73,64,92,74,66,64,22,51,27,30,83,30,37,25,22,46,95,59,57,21,29,72,7,56,47,48,54,75,67,33};

    // vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100};
    vector<int> nums = {100,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cout << Solution().canPartition(nums) << endl;

    return 0;
}