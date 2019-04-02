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
    // bool isPowerOfThree(int n) {
    //     if (n < 1) return false;
    //     while (n % 3 == 0) {
    //         n /= 3;
    //     }
    //     return n == 1;
    // }

    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        return 1162261467 % n == 0; 
    }
};

int main(int argc, char ** argv) {

    for(int t = 0; t < 244; t++)
    {
        cout << Solution().isPowerOfThree(t) << endl;
    }
    return 0;
}