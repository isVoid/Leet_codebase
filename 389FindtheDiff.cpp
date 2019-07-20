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
    //8ms 39.80%
    //9.2MB 22.58%
    // char findTheDifference(string s, string t) {
    //     map<char, int> bag;

    //     for (auto c : s) {
    //         if (bag.find(c) == bag.end()) {
    //             bag.insert(make_pair(c, 1));
    //         }
    //         else {
    //             bag[c]++;
    //         }   
    //     }

    //     for (auto c : t) {
    //         if (bag.find(c) != bag.end()) {
    //             bag[c]--;
    //             if (bag[c] < 0) {
    //                 return c;
    //             }
    //         }
    //         else {
    //             return c;
    //         }
    //     }

    //     return '0';
    // }


    // char findTheDifference(string s, string t) {
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());

    //     int i = 0, j = 0;

    //     while (i < s.size()) {
    //         if (s[i] != t[j]) {
    //             return t[j];
    //         }
    //         i++;
    //         j++;
    //     }

    //     return t[j];
    // }

    //4ms 91.90%
    //9MB 48.22%
    char findTheDifference(string s, string t) {
        char a = 0;
        for (auto c : s) {
            a ^= c;
        }
        for (auto c : t) {
            a ^= c;
        }

        return a;
    }
};

int main(int argc, char ** argv) {

    string s = "abcd", t = "abcde";
    // string s = "a", t = "aa";

    cout << Solution().findTheDifference(s, t) << endl;

    return 0;
}