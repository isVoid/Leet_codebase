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
    // bool isPowerOfFour(int n) {
    //     if (n < 1) return false;

    //     int num = n;
    //     int lz = 0, rz = 0;
    //     int prev = n;
    //     while (prev == n) {
    //         rz++;
    //         n = n >> rz;
    //         n = n << rz;
    //     }
    //     rz--;
    //     n = num;
    //     prev = n;
    //     while (prev == n) {
    //         lz++;
    //         n = n << lz;
    //         n = n >> lz;
    //     }

    //     // cout << lz << " " << rz << endl;
    //     return (lz + rz + 1) == 32 && rz % 2 == 0;

    // }

    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        if(num & (num - 1)) return false; //Make sure only 1 "1" bit in the number
        int cnt = 0;
        // Count zeroes on the left
        while(!(num&1))
        {
            num = num >> 1;
            cnt++;
        }
        return !(cnt%2);
    }
};

int main(int argc, char ** argv) {

    for (int i = 3; i < 17; i++) {
        cout << i << endl;
        cout << Solution().isPowerOfFour(i) << endl;
    }

    return 0;
}