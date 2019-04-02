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

    //BIT OPS
    //8 ms, faster than 95.81% 
    //8.1 MB
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1;
        int ones = 0;
        for (int i = 0; i < 32; i++) {
            if (n & mask) ones++;
            n = n >> 1;
        }
        return ones;
    }
};

int main() {

    // uint32_t t = 0b00000000000000000000000000001011;
    uint32_t t = 0b11111111111111111111111111111101;
    Solution s;
    cout << s.hammingWeight(t) << endl;

    return 0;
}