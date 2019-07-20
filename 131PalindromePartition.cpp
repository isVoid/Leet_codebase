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
// class Solution {
// public:

//     // bool isPalindrome(const string &s, int i, int j) {
//     //     if (i == j) {
//     //         return true;
//     //     }
//     //     else if (i == j+1) {
//     //         return s[i] == s[j];
//     //     }

//     //     return s[i] == s[j] && isPalindrome(s, ++i, --j);
//     // }

//     bool isPalindrome(const string &s, int i, int j) {
//         while (i <= j) {
//             if (s[i] != s[j]) {
//                 return false;
//             }
//             i++; j--;
//         }

//         return true;
//     }


//     vector< vector<string> > res;
//     set< pair<int, int> > dict;
//     vector< vector<string> > partition(string s) {
    //     vector<string> cur = vector<string>();
//         helper(cur, 0, s);
//         return res;
//     }

// Runtime: 20 ms, faster than 71.69% 
// Memory Usage: 14.7 MB, less than 68.04% 
//     void helper(vector<string> &cur, int index, string &s) {
//         if (index == s.length()) {
//             // printVector(cur);
//             res.emplace_back(cur);
//             return;
//         }

//         for (int j = index; j < s.size(); j++) {
//             if (dict.find({index, j}) == dict.end()) {
//                 if (isPalindrome(s, index, j)) {
//                     dict.insert({index, j});
//                     // cout << s.substr(i, j-i+1) << endl;
//                     cur.emplace_back(s.substr(index, j-index+1));
//                     helper(cur, j+1, s);
//                     cur.pop_back();
//                 }
//             }
//             else {
//                 cur.emplace_back(s.substr(index, j-index+1));
//                 helper(cur, j+1, s);
//                 cur.pop_back();
//             }

//         }
//     }
// };

class Solution {
public:

    vector< vector<string> > res;
    vector< vector<bool> > dp;
    // Runtime: 16 ms, faster than 78.17% 
    // Memory Usage: 13.6 MB, less than 75.79% 
    vector< vector<string> > partition(string s) {
        
        dp = vector< vector<bool> >(s.size(), vector<bool>(s.size(), false));

        //Fill dp value
        // for (int i = 0; i < s.size(); i++) {
        //     for (int j = 0; j < s.size(); j++) {
        //         if (i == 0 && j == 2) {
        //             cout << "";
        //         }
        //         if (i == j) {
        //             dp[i][j] = true;
        //         }
        //         else {
        //             dp[i][j] = (i+1 > j-1 || dp[i+1][j-1]) && s[i]==s[j];
        //         }
        //     }
        // }
        for (int l = 0; l < s.size(); l++) {
            for (int i = 0; i < s.size() - l; i++) {
                int j = i + l;
                // if (j > s.size()) continue;

                dp[i][j] = (i+1 > j-1 || dp[i+1][j-1]) && s[i]==s[j];
            }
        }


        printMatrix(dp);

        vector<string> cur = vector<string>();
        backtrack(cur, 0, s);

        return res;
    }

    void backtrack(vector<string> &cur, int i, string &s) {
        if (i == s.size()) {
            res.emplace_back(cur);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (dp[i][j]) {
                cur.emplace_back(s.substr(i, j-i+1));
                backtrack(cur, j+1, s);
                cur.pop_back();
            }
        }
    }
};

int main(int argc, char ** argv) {

    // string s = "aabbaa";
    // string s = "aabaa";
    // string s = "a";
    // string s = "abcab";
    // string s = "sdffds";

    // cout << Solution().isPalindrome(s, 0, s.size()-1) << endl;


    // string s = "aab";
    // cout << Solution().isPalindrome(s, 1, 2) << endl;
    // string s = "bb";
    string s = "efe";

    printMatrix(Solution().partition(s));

    return 0;
}