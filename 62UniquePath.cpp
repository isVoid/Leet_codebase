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

    int m, n;
    int h(int i, int j) {
        return i * n + j;
    }

    //4ms 100.0%
    //8.8MB 9.79%
    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;
        vector<int> routes(m*n, 0);
        routes[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                else if (i == 0) routes[h(i, j)] = routes[h(i, j-1)];
                else if (j == 0) routes[h(i, j)] = routes[h(i-1, j)];
                else routes[h(i, j)] = routes[h(i-1, j)] + routes[h(i, j-1)];
            }
        }
        return routes[h(m-1, n-1)];
    }
};

int main(int argc, char ** argv) {

    Solution s = Solution();
    // s.m = 3;
    // s.n = 2;
    // for (int i = 0; i < s.m; i++) {
    //     for (int j = 0; j < s.n; j++) {
    //         cout << s.h(i, j) << endl;
    //     }
    // }

    // cout << s.uniquePaths(3, 2) << endl;
    cout << s.uniquePaths(7, 3) << endl;

    return 0;
}