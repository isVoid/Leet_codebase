#include <iostream>
#include <vector>
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
    //20ms, 43.90%
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> dict;

        for (int i = 0; i < s.length(); i++) {
            if (dict.find(s[i]) == dict.end()) {
                dict[s[i]] = 1;
            }
            else {
                dict[s[i]]++;
            }
        }

        for (int i = 0; i < t.length(); i++) {
            if (dict.find(t[i]) == dict.end()) {
                return false;
            }
            else {
                dict[t[i]]--;
            }
        }

        for (auto k : dict) {
            if (k.second != 0) return false;
        }

        return true;
    }
};

int main(int argc, char ** argv) {

    // string s = "anagram", t = "nagaram";
    string s = "rat", t = "car";

    cout << Solution().isAnagram(s, t) << endl;

    return 0;
}