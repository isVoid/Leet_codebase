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

    //8ms 89.49%
    //9.2MB 71.18%
    bool isMatch(string s, string p) {
        //dp[i][j]: s[i:] matches with p[j:]
        vector< vector<bool> > dp(s.length()+1, vector<bool>(p.length()+1, false));

        //Base case: '' matches with ''
        dp[s.length()][p.length()] = true;

        for (int i = s.length(); i >= 0; i--) {
            for (int j = p.length()-1; j >= 0; j--) {
                bool current_match = i < s.length() &&
                    (s[i] == p[j] || p[j] == '.');

                if (j+1 < p.length() && p[j+1] == '*') {
                    dp[i][j] = dp[i][j+2] || (current_match && dp[i+1][j]);
                }
                else {
                    dp[i][j] = current_match && dp[i+1][j+1];
                }
            }
        }

        return dp[0][0];
    }
};

int main(int argc, char ** argv) {

    string s = "aaab";
    string p = "a*ab";

    cout << Solution().isMatch(s, p) << endl;

    return 0;
}