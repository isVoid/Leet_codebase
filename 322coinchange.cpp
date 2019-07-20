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

    //36ms 93.20%
    //12.7MB 59.91%
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0) return -1;
        if (amount == 0) return 0;

        int *dp = new int[amount+1];
        for (int i = 0; i <= amount; i++) {
            dp[i] = INT_MAX;
        }

        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] <= amount) {
                dp[coins[i]] = 1;
            }
        }

        for (int i = 0; i <= amount; i++) {
            cout << dp[i] << " ";
        }
        cout << endl;

        for (int i = 0; i <= amount; i++) {
            if (dp[i] == INT_MAX) {
                int n = INT_MAX;
                for (int coin : coins) {
                    if (i > coin) {
                        n = min(n, dp[i-coin]);
                    }
                }
                if (n != INT_MAX)
                    dp[i] = n + 1;
                else
                    dp[i] = INT_MAX;
            }
        }

        int ans = dp[amount] == INT_MAX ? -1 : dp[amount];

        //dbg
        for (int i = 0; i <= amount; i++) {
            cout << dp[i] << " ";
        }
        cout << endl;

        delete[] dp;

        return ans;

    }
};

int main(int argc, char ** argv) {

    // vector<int> coins = {2};
    // // vector<int> coins = {1, 2, 5};
    // int amount = 11;

    // vector<int> coins = {1};
    // // vector<int> coins = {1, 2, 5};
    // int amount = 0;

    vector<int> coins = {1};
    // vector<int> coins = {1, 2, 5};
    int amount = 1;

    cout << Solution().coinChange(coins, amount) << endl;

    return 0;
}