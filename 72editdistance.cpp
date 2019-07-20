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
    //12ms 92.85%
    //11.3MB 37.42%
    int minDistance(string word1, string word2) {
        vector< vector<int> > dp(word1.length()+1, vector<int>(word2.length()+1, 0));

        for (int i = 0; i <= word1.length(); i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= word2.length(); j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + 1);
                }
            }
        }

        printMatrix(dp);

        return dp[word1.length()][word2.length()];
    }
};

int main(int argc, char ** argv) {

    // string a = "horse", b = "ros";
    string a = "intention", b = "execution";

    cout << Solution().minDistance(a, b) << endl;

    return 0;
}