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
    //0ms 100%
    //9.1MB 77.09%
    string addStrings(string num1, string num2) {
        // int i = min(num1.length()-1, num2.length()-1);
        int i = num1.length()-1, j = num2.length()-1, k = max(num1.length(), num2.length())+1;
        vector<char> ans(k--, '0');
        int carry = 0;

        while (i >= 0 || j >= 0) {
            int a = i >= 0 ? num1[i] - '0' : 0;
            int b = j >= 0 ? num2[j] - '0' : 0;

            if (a + b + carry >= 10) {
                ans[k] += a + b + carry - 10;
                carry = 1;
            }
            else {
                ans[k] += a + b + carry;
                carry = 0;
            }
            i--;
            j--;
            k--;
        }

        if (carry) {
            ans[0] = '1';
        }

        // return string(ans.begin(), ans.end());
        return ans[0] == '1' ? string(ans.begin(), ans.end()) : string(ans.begin()+1, ans.end());
    }
};

int main(int argc, char ** argv) {

    // string a = "12334", b = "1111134134";
    // string a = "12334", b = "1111134134";
    // string a = "1", b = "8";
    string a = "1", b = "9999";
    
    string ans = Solution().addStrings(a, b);
    cout << ans.length() << endl;
    cout << Solution().addStrings(a, b) << endl;

    return 0;
}