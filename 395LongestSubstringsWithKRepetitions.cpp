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
    int longestSubstring(string s, int k) {
        int len = -1;
        for (int uniqueChar = 1; uniqueChar <= 26; uniqueChar++) {
            len = max(len, longSSUniqueChar(s, k, uniqueChar));
        }

        return len;
    }

    // Runtime: 4 ms, faster than 88.12% 
    // Memory Usage: 8.5 MB, less than 92.39% 
    // Divide and Conquer, sliding window template on substring problem
    // Subcase: number of unique characters
    int longSSUniqueChar(string &s, int k, int targetUnique) {
        int count[128] = {0};
        int i = 0, j = 0;
        int numK = 0, numUnique = 0;
        int l = -1;

        while (j < s.size()) {
            if (count[s[j]] == 0) {
                numUnique++;
            }
            count[s[j]]++;
            if (count[s[j]] == k) {
                numK++;
            }
            j++;

            while (numUnique > targetUnique) {
                if (count[s[i]] == k) {
                    numK--;
                }
                count[s[i]]--;
                if (count[s[i]] == 0) {
                    numUnique--;
                }
                i++;
            }

            if (numUnique == targetUnique && numK == numUnique) {
                l = max(l, j - i);
            }
        }

        return l;
    }
    
};

int main(int argc, char ** argv) {

    string s = "abaabc";

    cout << Solution().longestSubstring(s, 2) << endl;

    return 0;
}