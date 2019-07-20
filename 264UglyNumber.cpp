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
    //404ms 5.03%
    //15.1MB 13.78%
    // int nthUglyNumber(int n) {
    //     vector<unsigned long> u;
    //     u.push_back(1);

    //     for (int i = 0; i < n-1; i++) {
    //         unsigned long a = ULONG_MAX;
    //         for (int j = 0; j < u.size(); j++) {
    //             if (u[j] * 2 > u[i]) {
    //                 a = min(a, u[j] * 2);
    //             }
    //             else if (u[j] * 3 > u[i]) {
    //                 a = min(a, u[j] * 3);
    //             }
    //             else if (u[j] * 5 > u[i]) {
    //                 a = min(a, u[j] * 5);
    //             }
    //         }
    //         u.push_back(a);
    //     }

    //     printVector(u);

    //     return int(u[u.size()-1]);
    // }

    //8ms 94.93%
    //15.2MB 13.78%
    int nthUglyNumber(int n) {
        vector<unsigned long> u;
        u.push_back(1);
        int p = 0, q = 0, r = 0;

        for (int i = 1; i < n; i++) {
            u.push_back(min(min(u[p] * 2, u[q] * 3), u[r] * 5));
            if (u[i] == u[p] * 2) p++;
            if (u[i] == u[q] * 3) q++;
            if (u[i] == u[r] * 5) r++;
        }

        printVector(u);
        
        return u[u.size()-1];
    }
};

int main(int argc, char ** argv) {

    int n = 1959;

    cout << Solution().nthUglyNumber(n) << endl;

    return 0;
}