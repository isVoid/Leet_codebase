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

    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long dvnd = labs(dividend), dvsr = labs(divisor);
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        int quotient = 0;

        while (dvnd >= dvsr) {
            int shift = 0, tmp = dvsr;
            while (dvnd - tmp >= 0) {
                shift++;
                tmp = tmp << 1;
            }
            shift--;
            quotient += (1 << shift);
            dvnd -= (dvsr << shift);
            // cout << shift << " " << dvnd << endl;
        }

        return quotient * sign;
    }
};

int main(int argc, char ** argv) {

    int dividend = 20, divisor = 4;

    cout << Solution().divide(dividend, divisor) << endl;;

    return 0;
}