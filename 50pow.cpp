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
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        if ((x == 1.0 || x == -1.0 )&& n == INT_MIN) {
            return 1;
        }
        else if (n == INT_MIN) {
            return 0;
        }
        if (n < 0) {
            return 1 / myPow(x, -n);
        }
        //odd
        if (n & 1) {
            double r = myPow(x, n / 2);
            return r * r * x;
        }
        //even
        else {
            double r = myPow(x, n / 2);
            return r * r;
        }
    }
};

int main(int argc, char ** argv) {

    // int x = 2, n = 10;
    // double x = 9.1;
    // int n = 2;

    // double x = 1;
    // int n = -2;

    // double x = 2;
    // int n = -2;

    // double x = -1;
    // int n = -8;

    // double x = -1;
    // int n = 0;

    // double x = -1;
    // int n = INT_MIN;

    // cout << Solution().myPow(x, n) << endl;

    // cout << INT_MIN << " " << INT_MAX << endl;

    return 0;
}