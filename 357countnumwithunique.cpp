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

    int nCk(int n, int k) {
        int a = 1, b = 1;
        for (int i = 1; i <= k; i++) {
            a *= (n-i+1);
            b *= i;
        }
        return a/b;
    }

    //0ms 100%
    //8.3MB 23.90%
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp1 = {1, 10};
        vector<int> dp2 = {0, 9};

        for (int i = 2; i <= n && i <= 10; i++) {
            dp2.push_back(dp2[i-1] * nCk(11-i, 1));
            dp1.push_back(dp1[i-1] + dp2[i]);
        }

        printVector(dp1);
        printVector(dp2);

        if (n > 10) return dp1[10];
        else return dp1[n];

    }
};

int main(int argc, char ** argv) {

    int n = 1;
    // int n = 0;
    // int n = 2;
    // int n = 3;
    // int n = 14;

    cout << Solution().countNumbersWithUniqueDigits(n) << endl;

    return 0;
}