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

    //TLE
    //---

    // vector<string> dfs(string s) {
    //     // cout << s << endl;
    //     vector<string> scr;
    //     if (s.length() == 1) {
    //         scr.push_back(s);
    //         return scr;
    //     }
    //     for (int i = 1; i < s.length(); i++) {
    //         // cout << string(s.begin(), s.begin()+i) << endl;
    //         vector<string> leftscr = dfs(string(s.begin(), s.begin()+i));
    //         // cout << string(s.begin()+i, s.end()) << endl;
    //         vector<string> rightscr = dfs(string(s.begin()+i, s.end()));
    //         for (int m = 0; m < leftscr.size(); m++) {
    //             for (int n = 0; n < rightscr.size(); n++) {
    //                 scr.push_back(leftscr[m] + rightscr[n]);
    //                 scr.push_back(rightscr[n] + leftscr[m]);
    //             }
    //         }
    //     }

    //     // printVector(scr);
    //     return scr;
    // }

    // bool isScramble(string s1, string s2) {
    //     vector<string> as = dfs(s1);
    //     return find(as.begin(), as.end(), s2) != as.end();
    // }

    //TLE (but faster)
    //---
    // bool vs(string s1, string s2) {
    //     // cout << s1 << " " << s2 << endl;
    //     if (s1.length() != s2.length()) return false;
    //     vector<int> d(26, 0);
    //     for (int i = 0; i < s1.length(); i++) {
    //         d[s1[i] - 'a']++;
    //         d[s2[i] - 'a']--;
    //     }
    //     bool ans = true;
    //     for (int i = 0; i < d.size(); i++) {
    //         ans = ans && d[i] == 0;
    //     }
    //     return ans;
    // }

    // vector<string> dfs(string s, string s2, int st, int ed, vector< vector< vector<string> > >& dp) {
        
    //     // cout << st << " " << ed << endl;
    //     if (s.length() == 1) {
    //         dp[st][ed].push_back(s);
    //         return dp[st][ed];
    //     }
    //     for (int i = 1; i < s.length(); i++) {
            
    //         string l = string(s.begin(), s.begin()+i);
    //         string r = string(s.begin()+i, s.end());

    //         string s2l1 = string(s2.begin(), s2.begin()+i);
    //         string s2r1 = string(s2.begin()+i, s2.end());

    //         string s2l2 = string(s2.rbegin(), s2.rbegin()+i);
    //         string s2r2 = string(s2.rbegin()+i, s2.rend());

    //         bool v1 = vs(l, s2l1) && vs(r, s2r1);
    //         bool v2 = vs(l, s2l2) && vs(r, s2r2);

    //         if (v1) {
    //             // cout << l << " " << r << endl;
    //             // cout << s2l1 << " " << s2r1 << endl;
    //             // cout << string(s.begin(), s.begin()+i) << endl;
    //             vector<string> leftscr = dp[st][st+i-1].empty() ? dfs(l, s2l1, st, st+i-1, dp) : dp[st][st+i-1];
    //             // cout << string(s.begin()+i, s.end()) << endl;
    //             vector<string> rightscr = dp[st+i][ed].empty() ? dfs(r, s2r1, st+i, ed, dp) : dp[st+i][ed];
    //             for (int m = 0; m < leftscr.size(); m++) {
    //                 for (int n = 0; n < rightscr.size(); n++) {
    //                     dp[st][ed].push_back(leftscr[m] + rightscr[n]);
    //                     dp[st][ed].push_back(rightscr[n] + leftscr[m]);
    //                 }
    //             }
    //         }
    //         if (v2) {
    //             // cout << l << " " << r << endl;
    //             // cout << s2l2 << " " << s2r2 << endl;
    //             // cout << string(s.begin(), s.begin()+i) << endl;
    //             vector<string> leftscr = dp[st][st+i-1].empty() ? dfs(l, s2l2, st, st+i-1, dp) : dp[st][st+i-1];
    //             // cout << string(s.begin()+i, s.end()) << endl;
    //             vector<string> rightscr = dp[st+i][ed].empty() ? dfs(r, s2r2, st+i, ed, dp) : dp[st+i][ed];
    //             for (int m = 0; m < leftscr.size(); m++) {
    //                 for (int n = 0; n < rightscr.size(); n++) {
    //                     dp[st][ed].push_back(leftscr[m] + rightscr[n]);
    //                     dp[st][ed].push_back(rightscr[n] + leftscr[m]);
    //                 }
    //             }
    //         }
    //     }

    //     // printVector(scr);
    //     return dp[st][ed];
    // }

    // bool isScramble(string s1, string s2) {

    //     vector< vector <vector <string> > > dp(
    //         s1.length(), vector< vector<string> >(
    //             s1.length(), vector< string >()
    //         )
    //     );
        
    //     cout << "l1: " << dp.size() << " l2: " <<  dp[0].size() << " l3: " << dp[0][0].size() << endl;

    //     vector<string> as = dfs(s1, s2, 0, s1.length()-1, dp);
    //     printVector(as);

    //     return find(as.begin(), as.end(), s2) != as.end();
    // }

    //Recursion
    //---
    // bool isScramble(string s1, string s2) {

    //     if (s1.length() != s2.length()) return false;
    //     if (s1 == s2) return true;

    //     for (int i = 1; i < s1.length(); i++) {
    //         string l = s1.substr(0, i);
    //         string r = s1.substr(i);

    //         string s2l1 = s2.substr(0, i);
    //         string s2r1 = s2.substr(i);

    //         if (isScramble(l, s2l1) && isScramble(r, s2r1)) return true;

    //         string s2l2 = s2.substr(s2.length()-i);
    //         string s2r2 = s2.substr(0, s2.length()-i);

    //         if (isScramble(l, s2l2) && isScramble(r, s2r2)) return true;
    //     }

    //     return false;
    // }

    //dp
    //---
    //76ms 11.65%
    //12.4MB 42.84%
    bool isScramble(string s1, string s2) {

        if (s1.length() != s2.length()) return false;
        if (s1.length() == 0) return true;

        //dp[i][j][k]: if s1[i:i+k-1] isScramble of s2[j:j+k-1]
        vector< vector< vector<bool> > > dp(
            s1.length(), vector< vector<bool> >(
                s2.length(), vector<bool>(
                    s1.length()+1, false
                )
            )
        );

        //Base case:
        //For s1[i], s2[j], substring of length 1,
        //dp[i][j][1] true iff s1[i] == s2[j]
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                dp[i][j][1] = s1[i] == s2[j];
            }
        }

        //Induction case:
        //for any length l>=2, there exists 2 possible ways to determine if dp[i][j][l] is scrambable:
        //1. s1:[----k-------] s2:[----k-------] //dp[i][j][k] && dp[i+k][j+k][l-k]
        //2. s1:[----k-------] s2:[-------k----] //dp[i][j+l-k][k] && dp[i+k][j][l-k]
        for (int l = 2; l <= s1.length(); l++) {
            for (int i = 0; i < dp.size() - l + 1; i++) {
                for (int j = 0; j < dp[0].size() - l + 1; j++) {
                    for (int k = 1; k < l; k++) {
                        // cout << i << " " << j << " " << l << " " << k << endl;
                        // cout << i+k << " " << j+k << endl;
                        dp[i][j][l] = dp[i][j][l] || (dp[i][j][k] && dp[i+k][j+k][l-k]) || (dp[i][j+l-k][k] && dp[i+k][j][l-k]);
                    }
                }
            }
        }

        return dp[0][0][s1.length()];
    }
};

int main(int argc, char ** argv) {

    // string s = "abcde";
    // string t = "caebd";

    // string s = "great";
    // string t = "rgeat";

    // string s = "abcdefghijklmn";
    // string t = "efghijklmncadb";

    string s = "abb";
    string t = "bba";

    // string s = "oatzzffqpnwcxhejzjsnpmkmzngneo";
    // string t = "acegneonzmkmpnsjzjhxwnpqffzzto";

    // cout << Solution().vs(s, t) << endl;

    // printVector(Solution().dfs(s, 0, s.length()-1));
    cout << Solution().isScramble(s, t) << endl;;

    return 0;
}