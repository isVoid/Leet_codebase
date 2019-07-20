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

    // int atoi(string &a, int &i) {
    //     int r = 0;
    //     long mul = 1;
    //     int j = i;
    //     for (; j >= 0 && a[j] >= '0' && a[j] <= '9'; j--) {
    //         r += (a[j] - '0') * mul;
    //         mul *= 10;
    //     }
    //     i = j;
    //     return r;
    // }


    // //Evaluate Expression Untill next ')'
    // int evalExpr(stack<int> &numstack, stack<char> &opstack) {
    //     int res = numstack.top();
    //     numstack.pop();
    //     while (!opstack.empty() && opstack.top() != ')') {
    //         char op = opstack.top();
    //         opstack.pop();
    //         if (op == '+') {
    //             res = res + numstack.top();
    //         }
    //         else {
    //             res = res - numstack.top();
    //         }
    //         numstack.pop();
    //     }
    //     if (!opstack.empty())
    //         opstack.pop(); //')'
    //     return res;
    // }

    // //Reverse String
    // 12 ms	11.1 MB
    // int calculate(string s) {
    //     stack<int> numstack;
    //     stack<char> opstack;

    //     for (int i = s.length()-1; i >= 0;) {
    //         if (s[i] == ')') {
    //             opstack.push(')');
    //             i--;
    //         }
    //         else if (s[i] >= '0' && s[i] <= '9') {
    //             // string nextString = nextIntString(s, i); 
    //             numstack.push(atoi(s, i));
    //         }
    //         else if (s[i] == '(') {
    //             int res = evalExpr(numstack, opstack);
    //             numstack.push(res);
    //             i--;
    //         }
    //         else if (s[i] != ' ') {  //Ops
    //             opstack.push(s[i]);
    //             i--;
    //         }
    //         else {
    //             i--;
    //         }
    //         printStack(numstack);
    //         printStack(opstack);
    //         cout << i << ": ---" << endl;
    //     }

    //     if (numstack.size() == 1) {
    //         return numstack.top();
    //     }
        
    //     int res = evalExpr(numstack, opstack);

    //     return res;

    // }

    //Forward String
    // Runtime: 12 ms, faster than 90.74%
    // Memory Usage: 10.3 MB, less than 77.03%
    int calculate(string s) {
        
        stack<char> sign;
        stack<int> nums;
        int res = 0, curOpr = 0;
        char lastOp = '+';
        for (char &c : s) {
            printStack(sign);
            printStack(nums);
            cout << res << endl;
            cout << "---" << endl;
            if (c == '(') {
                nums.push(res);
                sign.push(lastOp);
                res = 0;
                lastOp = '+';
            }
            else if (c >= '0' && c <= '9') {
                curOpr = curOpr * 10 + (c - '0');
            }
            else if (c == ')') {
                if (lastOp == '+') {
                    res += curOpr;
                }
                else {
                    res -= curOpr;
                }
                if (sign.top() == '-') {
                    // res += nums.top();
                    lastOp = '-';
                }
                else {
                    // res = nums.top() - res;
                    lastOp = '+';
                }
                curOpr = res;
                res = nums.top();
                nums.pop();
                sign.pop();
                // lastOp = sign.top();
            }
            else if (c != ' ') { //Op
                if (lastOp == '+') {
                    res += curOpr;
                }
                else {
                    res -= curOpr;
                }
                curOpr = 0;
                lastOp = c;
            }
        }

        // printStack(sign);
        // printStack(nums);
        // cout << res << endl;
        // cout << lastOp << endl;
        // cout << curOpr << endl;
        // cout << "---" << endl;

        if (lastOp == '+') res += curOpr;
        else res -= curOpr;

        return res;

    }
};

int main(int argc, char ** argv) {

    // string expr = "1 + 1";
    // string expr = "2 - 1 + 2";
    // string expr = "2 - 1 + 2";

    // string expr = "(1+(4+5+2)-3)+(6+8)";
    string expr = "2-4-(8+2-6+(8+4-(1)+8-10))";
    
    cout << Solution().calculate(expr) << endl;

    return 0;
}