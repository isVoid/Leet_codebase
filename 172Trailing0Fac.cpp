#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include "dbg.hpp"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // 1. Factorizing the number and find out all
    // 2s and 5s will get the result.
    // 2. Easy too see there are more 5s than 2s
    // in the prime factors. So only counting 5s
    // in prime factor will suffice

    // An easy way to count 5s: floor(n/5)?
    // Factor 25 has two 5s!
    // Thus floor(n/5) + floor(n/25) + floor(n/125)...
    // Assumption: count of 2s >> count of 5s
    // which is true.

    // 12ms, 60.98%
    // int trailingZeroes(int n) {
    //     unsigned long long z = 0;
    //     unsigned long long nn = (unsigned long long) n;
    //     for (unsigned long long i = 5; n / i >= 1; i *= 5) {
    //         z += n / i;
    //     }
    //     return z;
    // }

    // 8ms, 100%
    int trailingZeroes(int n) {
        long z = 0;
        long nn = long (n);
        for (long i = 5; n / i >= 1; i *= 5) {
            z += n / i;
        }
        return z;
    }
};

int main() {

    int t = 30;
    Solution s;

    cout << s.trailingZeroes(t) << endl;

    return 0;
}