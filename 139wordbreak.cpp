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
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     if (s.length() == 0) return true;
    //     cout << s << endl;

    //     bool ans = false;
    //     for (string word : wordDict) {
    //         int l = word.length();
    //         if (s.substr(0, l).compare(word) == 0) {
    //             ans = ans || wordBreak(s.substr(l), wordDict);
    //         }
    //     }
    //     return ans;
    // }

    //32ms 14.33%
    //14.2MB 56.84%
    // bool match(string ss, vector<string>& dict) {
    //     for (string w : dict) {
    //         if (ss.compare(w) == 0) return true;
    //     }
    //     return false;
    // }

    // bool wordBreak(string s, vector<string>& wordDict) {
    //     bool b[s.length()+1];
    //     memset(b, 0, sizeof(b) / sizeof(bool));

    //     for (int i = 1; i <= s.length(); i++) {
    //         if (b[i] == false && match(s.substr(0, i), wordDict)) 
    //             b[i] = true;

    //         if (b[i] == true) {
    //             if (i == s.length()) return true;

    //             for (int j = i+1; j <= s.length(); j++) {
    //                 if (b[j] == false && match(s.substr(i, j-i), wordDict)) 
    //                     b[j] = true;
    //                 if (b[j] == true && j == s.length()) return true;
    //             }
    //         }
    //     }

    //     for (int i = 0; i < s.length(); i++) {
    //         cout << b[i] << endl;
    //     }

    //     return false;
    // }

    bool match(string ss, vector<string>& dict) {
        for (string w : dict) {
            if (ss.compare(w) == 0) return true;
        }
        return false;
    }

    //24ms 34.35%
    //10.8MB 80.20%
    bool wordBreak(string s, vector<string>& wordDict) {
        bool b[s.length()+1];
        memset(b, 0, sizeof(b) / sizeof(bool));

        vector<int> mI;
        mI.push_back(-1);

        for (int i = 0; i <= s.length(); i++) {
            size_t sz = mI.size() - 1;
            bool m = false;
            for (int j = sz; j >= 0; j--) {
                if (match(s.substr(mI[j]+1, i-mI[j]), wordDict)) {
                    m = true;
                    break;
                }
            }

            if (m) {
                b[i] = true;
                mI.push_back(i);
            }
        }

        for (int i = 0; i < s.length(); i++) {
            cout << b[i] << " ";
        }
        cout << endl;
        for (int a : mI) {
            cout << a << " ";
        }
        cout << endl;

        return b[s.length()];
    }
};

int main(int argc, char ** argv) {

    // vector<string> words = {"leet", "code"};
    // string s = "leetcode";
    // vector<string> words = {"apple", "pen", "apple"};
    // string s = "applepenapple";
    // vector<string> words = {"cats", "dog", "sand", "and", "cat"};
    // string s = "catsandog";

    // vector<string> words = {"a"};
    // string s = "a";

    vector<string> words = {"a", "b"};
    string s = "ab";

    cout << Solution().wordBreak(s, words) << endl;

    return 0;
}