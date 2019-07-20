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
    //36ms 95.57%
    //12.8MB 87.09%
    //词典计数法，通过建立a-z的词典计数。本质是哈希
    int firstUniqChar(string s) {
        int *dict = new int[26]{};

        for (int i = 0; i < s.length(); i++) {
            dict[s[i]-'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (dict[s[i]-'a'] == 1) return i;
        }

        return -1;
    }
};

int main(int argc, char ** argv) {

    // string a = "leetcode";
    string a = "loveleetcode";

    cout << Solution().firstUniqChar(a) << endl;

    return 0;
}
