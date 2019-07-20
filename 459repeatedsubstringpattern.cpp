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
    //1272ms 5.01%
    //739.7MB 5.08%
    // bool repeatedSubstringPattern(string s) {
    //     for (int len = 1; len <= s.length() / 2; len++) {
    //         string proto = s.substr(0 ,len);
    //         string s2 = s;
    //         while (proto == s2.substr(0, len)) {
    //             s2 = s2.substr(len);
    //         }
    //         cout << proto << " " << s2 << endl;
    //         if (s2.empty())
    //             return true;
    //     }
    //     return false;
    // }

    //32ms 90.86%
    //11.5MB 95.18%
    //Cope with 10^4 length
    //Performance key: 1. length pruning, only multiples of l makes s.length.
    //2. if repeated, two pointers will match all the way to the end.
    bool repeatedSubstringPattern(string s) {
        for (int l = 1; l <= s.length() / 2; l++) {
            if (s.length() % l == 0) {
                int i = 0, j = i+l;
                while (j < s.length() && s[i] == s[j]) {
                    i++;
                    j++;
                }
                cout << l << " " << i << " " << j << endl;
                if (j == s.length()) return true;
            }
        }
        return false;
    }
};
int main(int argc, char ** argv) {

    // string s = "abcabc";
    // string s = "aba";
    // string s = "abcdabcde";
    // string s = "";
    string s = "aabaaba";

    cout << Solution().repeatedSubstringPattern(s) << endl;

    return 0;
}