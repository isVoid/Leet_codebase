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
    // Runtime: 0 ms, faster than 100.00%
    // Memory Usage: 8.9 MB, less than 55.48%
    vector< vector<int> > generateMatrix(int n) {
        vector< vector<int> > mat(n, vector<int>(n, 0));
        if (n == 0) return mat;
        n = n - 1;

        int k = 0;
        int a = 1;

        while (k <=  n / 2) {
            //top
            for (int i = k; i < n - k; i++) {
                mat[k][i] = a++;
            }
            //right
            for (int i = k; i < n - k; i++) {
                mat[i][n-k] = a++;
            }
            //bottom
            for (int i = n-k; i > k; i--) {
                mat[n-k][i] = a++;
            }
            //left
            for (int i = n-k; i > k; i--) {
                mat[i][k] = a++;
            }
            k++;
        }
        if ((n+1)&1) {
            mat[n/2][n/2] = a;
        }
        return mat;
    }
};

int main(int argc, char ** argv) {

    // printMatrix(Solution().generateMatrix(5));
    // printMatrix(Solution().generateMatrix(4));
    
    for (int i = 0; i <= 10; i++) {
        printMatrix(Solution().generateMatrix(i));
    }

    // printMatrix(Solution().generateMatrix(0));
    // printMatrix(Solution().generateMatrix(1));

    return 0;
}