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
    // bool isPerfectSquare(int num) {
    //     long long l = num;
    //     for (long long i = 1; i <= num; i++) {
    //         long long ii = i * i;
    //         if (ii == l) return true;
    //         if (ii > l) return false;
    //     }

    //     return false;
    // }

    //BinSearch
    //100.0%  0ms
    //8.1MB 23.69%
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;
        int a = 0, b = num;
        while (a + 1 < b) {
            // cout << a << " " << b << endl;
            long long c = (a + b) / 2;
            if (c * c == num) {
                return true;
            }
            else if (c * c > num) {
                b = c;
            }
            else {
                a = c;
            }
        }

        return false;
    }
};

int main(int argc, char ** argv) {

    // int n = 16;
    // int n = 14;
    // int n = 64;
    // int n = 101;
    // int n = 1;
    // int n = 4;
    int n = 0;

    cout << Solution().isPerfectSquare(n) << endl;

    return 0;
}