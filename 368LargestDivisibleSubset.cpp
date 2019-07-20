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
    // vector<int> largestDivisibleSubset(vector<int>& nums) {
    //     vector< vector<int> > lds;
    //     if (nums.size() == 0) return {};
    //     if (nums.size() == 1 && nums[0] == 1) {
    //         return {1};
    //     }

    //     bool hasOne = false;
    //     int curMax = 0;
    //     int ans = 0;

    //     sort(nums.begin(), nums.end());

    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] == 1) {
    //             hasOne = true;
    //             continue;
    //         }

    //         int flag = 0;
    //         for (int j = 0; j < lds.size(); j++) {
    //             int maxA = *(lds[j].end()-1);
    //             int minA = hasOne ? *(lds[j].begin()+1) : *lds[j].begin();

    //             if (nums[i] % maxA == 0) {
    //                 lds[j].push_back(nums[i]);
    //                 cout << lds[j].size() << " " << curMax << endl; 
    //                 if (lds[j].size() > curMax) {
    //                     curMax = lds[j].size();
    //                     ans = j;
    //                 }
    //                 flag = 1;
    //                 break;
    //             }
    //             else if (nums[i] % minA == 0) {
    //                 flag = minA;
    //             }
    //         }

    //         cout << "dbg: " << nums[i] << " " << ans << " " << flag << endl;

    //         if (flag == 0) {
    //             vector<int> n;
    //             if (hasOne) n.push_back(1);
    //             n.push_back(nums[i]);
    //             lds.push_back(n);
    //         }
    //         else if (flag != 1) {
    //             vector<int> n;
    //             if (hasOne) n.push_back(1);
    //             n.push_back(flag);
    //             n.push_back(nums[i]);
    //             lds.push_back(n);
    //         }
    //     }

    //     //dbg
    //     for (int i = 0; i < lds.size(); ++i) {
    //         printVector(lds[i]);
    //     }

    //     return lds[ans];
    // }

    //28ms 82.09%
    //9MB 60.76%
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> dp(nums.size(), 0);
        vector<int> p(nums.size(), 0);

        int m = 0;
        int mi = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j]+1) {
                    dp[i] = dp[j] + 1;
                    p[i] = j;

                    if (dp[i] > m) {
                        m = dp[i];
                        mi = i;
                    }
                }
            }
        }

        vector<int> ret;
        for (int i = 0; i < m; i++) {
            ret.push_back(nums[mi]);
            mi = p[mi];
        }

        sort(ret.begin(), ret.end());

        printVector(dp);
        printVector(p);

        return ret;
    }   

};

int main(int argc, char ** argv) {

    // vector<int> a = {1, 2, 3};
    vector<int> a = {1, 2, 4, 8};
    // vector<int> a = {1, 121, 242, 2, 4, 8};
    // vector<int> a = {1, 121, 242, 2, 4, 8, 3, 6, 9, 11};
    // vector<int> a = {1, 3, 6, 9, 27};
    // vector<int> a = {1};
    // vector<int> a = {2};
    // vector<int> a = {546, 669};
    // vector<int> a = {3, 4, 16, 8};

    printVector(Solution().largestDivisibleSubset(a));

    return 0;
}