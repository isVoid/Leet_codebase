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
    //20ms 75.85%
    //9.1MB 31.69%

    int getMoneyAmount(int n) {
        vector< vector<int> > dp(n+2, vector<int>(n+2, 0));

        printMatrix(dp);

        //Base case is length of seq == 1
        for (int len = 1; len <= n; len++) {
            //i is start of seqence
            for (int i = 1; i <= n-len; i++) {
                //j is end of sequence
                int j = i + len;

                dp[i][j] = INT_MAX;
                //For neighboring numbers, guess smaller ones
                if (len == 1) {
                    dp[i][j] = i;
                }
                else {
                    //k is the divider
                    for (int k = i; k <= j; k++) {
                        // dp[i][j] = min(dp[i][j], dp[i][k-1]+dp[k+1][j]+k);
                        dp[i][j] = min(dp[i][j], k + max(dp[i][k-1], dp[k+1][j]));
                    }
                }
            }
        }
        
        printMatrix(dp);
        return dp[1][n];
    }
};

int main(int argc, char ** argv) {

    int n = 10;

    cout << Solution().getMoneyAmount(n) << endl;

    return 0;
}