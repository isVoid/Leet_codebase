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

    //4ms 100%
    //8.1MB 45.3%
    int maxDivide(int n, int a) {
        while (n % a == 0) {
            n = n / a;
        }
        return n;
    }

    bool isUgly(int num) {
        if (num == 0) return false;
        num = maxDivide(num, 2);
        num = maxDivide(num, 3);
        num = maxDivide(num, 5);
        cout << "remain num: " << num << endl;
        return num == 1;
    }
};

int main(int argc, char ** argv) {

    int t = 25;
    int t2 = 36;
    int t3 = 14;
    int t4 = 1;
    int t5 = -36;
    int t6 = 233423445;
    int t7 = 0;
    int t8 = -2147483648;

    Solution s;
    // cout << s.isUgly(t) << endl;
    // cout << s.isUgly(t2) << endl;
    // cout << s.isUgly(t3) << endl;
    // cout << s.isUgly(t4) << endl;
    // cout << s.isUgly(t5) << endl;
    // cout << s.isUgly(t6) << endl;
    // cout << s.isUgly(t7) << endl;
    cout << s.isUgly(t8) << endl;

    return 0;
}