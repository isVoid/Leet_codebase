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
    //8ms 95.60%
    //9MB 57.00%
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() <= 1) return 0;

        vector<int> dp = {cost[0], cost[1]};

        for (int i = 2; i < cost.size(); i++) {
            dp.push_back(min(cost[i]+dp[i-2], cost[i]+dp[i-1]));
        }

        printVector(dp);
        return min(dp[dp.size()-1], dp[dp.size()-2]);
    }
};
int main(int argc, char ** argv) {

    // vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> cost = {10, 15, 20};
    cout << Solution().minCostClimbingStairs(cost) << endl;

    return 0;
}