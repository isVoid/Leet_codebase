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
    //64ms 80.04%
    //17.1MB 26.22%
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        printf("Debug: %d, %d\n", i, j);
        if (i == s.size()) return true;
        else return false;
    }
};

int main(int argc, char ** argv) {

    // string s = "abc";
    string s = "axc";
    string t = "ahbgdc";

    cout << Solution().isSubsequence(s, t) << endl;

    return 0;
}