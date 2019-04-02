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
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        double intpart;
        return modf(log2(n), &intpart) == 0;
    }
};

int main(int argc, char ** argv) {

    int a = 16;
    Solution s;

    cout << s.isPowerOfTwo(a) << endl;

    return 0;
}