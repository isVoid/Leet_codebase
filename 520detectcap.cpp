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

    bool C(char a) {
        return a >= 'A' && a <= 'Z';
    }
    // bool NC(char a) {
    //     return a >= 'a' && a <= 'z';
    // }
    //state machine
    //0ms 100%
    //8.1MB 89.19%
    bool detectCapitalUse(string w) {
        if (w.empty()) return true;
        int state;
        if (C(w[0])) state = 2;
        else state = 1;

        for (int i = 1; i < w.length(); i++) {
            cout << state << endl;
            if (state == 1) {
                if (C(w[i])) return false;
            }
            else if (state == 2) {
                if (C(w[i])) state = 4;
                else state = 5;
            }
            else if (state == 4) {
                if (!C(w[i])) return false;
            }
            else if (state == 5) {
                if (C(w[i])) return false;
            }
        }

        return true;
    }
};

int main(int argc, char ** argv) {

    // string s = "USA";
    // string s = "FlaG";
    string s = "Leetcode";

    cout << Solution().detectCapitalUse(s) << endl;
    
    return 0;
}