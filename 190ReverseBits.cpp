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
    //Bit ops
    //4ms 100%
    //8MB
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask = 1;
        uint32_t r = 0;
        for(size_t i = 0; i < 32; i++)
        {
            r = r << 1;
            uint32_t b = (n & mask);
            // printBits(sizeof(r), &r);
            // printBits(sizeof(b), &b);
            r = r ^ b;
            n = n >> 1;

            // cout << endl;
        }
        return r;
    }
};

int main() {

    uint32_t t = 0b00000010100101000001111010011100;
    // uint32_t t = 0b11111111111111111111111111111101;
    printBits(sizeof(t), &t);

    Solution s;
    t = s.reverseBits(t);
    printBits(sizeof(t), &t);

    return 0;
}