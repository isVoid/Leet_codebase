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
    //0ms 100.0%
    //9.1MB 57.00%
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

        vector<int> dp1;    //rest
        vector<int> dp2;    //buy
        vector<int> dp3;    //sell

        int maxBought = -prices[0];

        dp1.push_back(0);
        dp2.push_back(-prices[0]);
        dp3.push_back(0);

        for (int i = 1; i < prices.size(); i++) {
            dp1.push_back(max(max(dp1[i-1], dp2[i-1]), dp3[i-1]));
            dp2.push_back(dp1[i-1] - prices[i]);
            dp3.push_back(maxBought + prices[i]);

            if (dp2[i] > maxBought) maxBought = dp2[i];
        }

        return max(max(dp1[dp1.size()-1], dp2[dp2.size()-1]), dp3[dp3.size()-1]);
    }
};

int main(int argc, char ** argv) {

    // vector<int> p = {1,2,3,0,2};
    // vector<int> p = {1, 4, 6, 5, 0, 2};
    // vector<int> p;
    // vector<int> p = {1};
    // vector<int> p = {1, 0};
    vector<int> p = {0, 1};

    cout << Solution().maxProfit(p) << endl;

    return 0;
}