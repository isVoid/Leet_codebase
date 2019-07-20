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
    // //368ms 7.97%
    // //13.6MB 61.96%
    // bool isMatch(string s, string p) {
    //     vector< vector<bool> > dp(s.length()+1, vector<bool>(p.length()+1, false));

    //     dp[s.length()][p.length()] = true;

    //     for (int i = s.length(); i >= 0; i--) {
    //         for (int j = p.length()-1; j >= 0; j--) {

    //             bool match = i < s.length() && j < p.length() && (s[i] == p[j] || p[j] == '?');

    //             if (p[j] == '*') {
    //                 dp[i][j] = dp[i][j] || dp[i][j+1];
    //                 if (dp[i][j]) {
    //                     for (int k = 0; k <= i; k++) {
    //                         dp[k][j] = true;
    //                     }
    //                 }
    //             }
    //             else {
    //                 dp[i][j] = dp[i][j] || (match && dp[i+1][j+1]);
    //             }
    //         }
    //     }

    //     //dbg
    //     printMatrix(dp);

    //     return dp[0][0];
    // }

    //8ms 98.34%
    //8.9MB 86.30%
    bool isMatch(string s, string p) {
        int i = 0, j = 0, jstar = -1, istar = -1;

        while (i < s.length()) {

            if ( s[i] == p[j] || p[j] == '?') {
                i++;
                j++;
            }
            else if (p[j] == '*') {
                istar = i;
                jstar = j;
                j++;
            }
            else if (jstar >= 0) {
                if (j != jstar + 1) {
                    istar++;
                    i = istar;
                    j = jstar + 1;
                }
                else {
                    i++;
                    istar = i;
                }
                // i = j == jstar + 1 ? i+1 : i;
                // j = jstar + 1;
            }
            else {
                return false;
            }
            cout << s[i] << " " << p[j] << endl;
        }

        while (j < p.length() && p[j] == '*') j++;

        return j == p.length();
    }
};

int main(int argc, char ** argv) {

    // string s = "adceb";
    // string p = "*a*b";

    // string s = "acbcb";
    // string p = "a*c?b";

    // string s = "cb";
    // string p = "?a";

    // string s = "abasdfxcv";
    // string p = "*";

    // string s = "starwars";
    // string p = "star*";

    // string s = "starwars";
    // string p = "start*";

    // string s = "starwars";
    // string p = "a*";

    // string s = "abcde";
    // string p = "*de";

    // string s = "abcde";
    // string p = "abc*de";

    // string s = "aa";
    // string p = "a";

    // string s = "aaaa";
    // string p = "***a";

    string s = "abcdede";
    string p = "a*de";

    // string s = "abc";
    // string p = "abc*";

    // string s = "abc";
    // string p = "abc***";

    // string s = "mississippi";
    // string p = "m*issip*";

    // string s = "mississippi";
    // string p = "m??*ss*?i*pi";

    cout << Solution().isMatch(s, p) << endl;

    return 0;
}