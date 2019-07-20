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

    int atoi(string s) {
        int i = s.length()-1;
        int sign = s[0] == '-' ? -1 : 1;
        int res = 0, mul = 1;
        while (i >= 0 && s[i] != '-') {
            res += (s[i] - '0') * mul;
            mul *= 10;
            i--;
        }

        return res * sign;
    }

    // Runtime: 12 ms, faster than 92.26%
    // Memory Usage: 11.6 MB, less than 38.18%
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for (string s : tokens) {
            printStack(num);
            if (s[0] == '+') {
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                num.push(a + b);
            }
            else if (s[0] == '-' && s.size() == 1) {
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                num.push(b - a);
            }
            else if (s[0] == '*') {
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                num.push(a * b);
            }
            else if (s[0] == '/') {
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                num.push(b / a);
            }
            else {
                num.push(atoi(s));
            }
        }
        return num.top();
    }
};

int main(int argc, char ** argv) {

    // vector<string> v = {"2", "1", "+", "3", "*"};
    // vector<string> v = {"4", "13", "5", "/", "+"};
    vector<string> v = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    cout << Solution().evalRPN(v) << endl;

    return 0;
}