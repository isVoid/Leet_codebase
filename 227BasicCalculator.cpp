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

    int parseNextInt(string &s, int &i) {

        //skip spaces
        while (i < s.size() && s[i] == ' ')
            i++;

        int j = i;
        while (j < s.size() && s[j] >= '0' && s[j] <= '9') {
            j++;
        }
        int end = j;
        j--;

        long mul = 1;
        int res = 0;
        while (j >= i) {
            res += ((s[j] - '0') * mul);
            mul *= 10;
            j--;
        }

        i = end;
        return res;
    }

    char parseNextOp(string &s, int &i) {

        while (i < s.size() && s[i] == ' ')
            i++;

        char c = s[i];
        i++;

        return c;
    }

    // int computeMulQueue(vector<int> &mulQueue, vector<char> &mulOps) {
    //     if (mulQueue.size() == 0) {
    //         return 0;
    //     }
    //     if (mulQueue.size() == 1) {
    //         return mulQueue[0];
    //     }
    //     int ans = -1;
    //     for (int i = 1, j = 0; i < mulQueue.size(); i++, j++) {
    //         int oprnd1 = mulQueue[i-1], oprnd2 = mulQueue[i];
    //         if (ans == -1) {
    //             ans = mulOps[j] == '*' ? oprnd1 * oprnd2 : oprnd1 / oprnd2;
    //         }
    //         else {
    //             ans = mulOps[j] == '*' ? ans * oprnd2 : ans / oprnd2;
    //         }
    //     }
    //     mulQueue.clear();
    //     mulOps.clear();
    //     return ans;
    // }

    // int computePlusQueue(vector<int> &plusQueue, vector<char> &plusOps) {
    //     if (plusQueue.size() == 0) {
    //         return 0;
    //     }
    //     if (plusQueue.size() == 1) {
    //         return plusQueue[0];
    //     }

    //     int ans = plusOps[0] == '+' ? 
    //         plusQueue[0] + plusQueue[1] : plusQueue[0] - plusQueue[1];

    //     for (int i = 2, j = 1; i < plusQueue.size(); i++, j++) {
    //         int oprnd = plusQueue[i];
    //         ans = plusOps[j] == '+' ? ans + oprnd : ans - oprnd;
    //     }
    //     plusQueue.clear();
    //     plusOps.clear();
    //     return ans;
    // }

    // // Runtime: 48 ms, faster than 9.52% 
    // // Memory Usage: 16.8 MB, less than 6.77% 
    // int calculate(string s) {
    //     //strip spaces
    //     //erase-remove idiom
    //     s.erase(remove(s.begin(), s.end(), ' '), s.end());
    //     s.push_back('&');

    //     vector<int> plusQueue;
    //     vector<char> plusOps;

    //     vector<int> mulQueue;
    //     vector<char> mulOps;

    //     int i = 0;
    //     while (i < s.size()) {
    //         int nextInt = parseNextInt(s, i);
    //         char op = s[i];
    //         // cout << nextInt << " " << op << endl;

    //         if (op == '+' || op == '-' || op == '&') {
    //             if (mulQueue.empty()) {
    //                 plusQueue.push_back(nextInt);
    //                 plusOps.push_back(op);
    //             }
    //             else {
    //                 mulQueue.push_back(nextInt);
    //                 int mulRes = computeMulQueue(mulQueue, mulOps);
    //                 plusQueue.push_back(mulRes);
    //                 plusOps.push_back(op);
    //             }
    //         }
    //         else if (op == '*' || op == '/') {
    //             mulQueue.push_back(nextInt);
    //             mulOps.push_back(op);
    //         }
    //         i++;
    //     }

    //     plusOps.pop_back(); //terminal symbol
    //     int ans = computePlusQueue(plusQueue, plusOps);

    //     return ans;
        
    // }

    // Runtime: 12 ms, faster than 92.49% 
    // Memory Usage: 10.2 MB, less than 79.93% 
    int calculate(string s) {
        //strip spaces
        //erase-remove idiom
        // s.erase(remove(s.begin(), s.end(), ' '), s.end());
        s.push_back('&');

        int plusResult = 0;
        char lastPlusOp = ' ';

        int mulResult = 1;
        char lastMulOp = ' ';

        int i = 0;
        while (i < s.size()) {
            int nextInt = parseNextInt(s, i);
            char op = parseNextOp(s, i);

            if (op == '+' || op == '-' || op == '&') {
                if (lastMulOp == ' ') {
                    if (lastPlusOp == '+') {
                        plusResult += nextInt;
                    }
                    else if (lastPlusOp == '-') {
                        plusResult -= nextInt;
                    }
                    else {
                        plusResult = nextInt;
                    }
                    lastPlusOp = op;
                }
                else {
                    mulResult = lastMulOp == '*' ? mulResult * nextInt :
                        mulResult / nextInt;
                    if (lastPlusOp == '+') {
                        plusResult += mulResult;
                    }
                    else if (lastPlusOp == '-') {
                        plusResult -= mulResult;
                    }
                    else {
                        plusResult = mulResult;
                    }
                    mulResult = 1;
                    lastMulOp = ' ';
                    lastPlusOp = op;
                }
            }
            else if (op == '*' || op == '/') {
                if (lastMulOp == ' ') {
                    mulResult = nextInt;
                    lastMulOp = op;
                }
                else {
                    mulResult = lastMulOp == '*' ? mulResult * nextInt :
                        mulResult / nextInt;
                    lastMulOp = op;
                }
            }
        }

        return plusResult;
    }
};

int main(int argc, char ** argv) {

    // vector<int> mulQueue = {2, 5, 4, 2};
    // vector<char> mulOps = {'*', '*', '/'};
    // vector<int> mulQueue = {3, 7, 6};
    // vector<char> mulOps = {'*', '/'};

    // cout << Solution().computeMulQueue(mulQueue, mulOps) << endl;

    // vector<int> plusQueue = {3, 7, 6};
    // vector<char> plusOps = {'+', '-'};

    // vector<int> plusQueue = {24, 6, 8};
    // vector<char> plusOps = {'+', '+'};

    // vector<int> plusQueue = {6, 8, 24};
    // vector<char> plusOps = {'-', '-'};

    // cout << Solution().computePlusQueue(plusQueue, plusOps) << endl;

    // string s = "2 - 3 + 4";
    string s = "3 + 2 * 2";
    // string s = "2-1 + 2";
    // string s = " 3/2 ";
    // string s = "2147483647";
    cout << Solution().calculate(s) << endl;

    // string s = "2147483647";
    // string s = "123456";
    // int i = 0;
    // cout << Solution().parseNextInt(s, i) << endl;

    return 0;
}