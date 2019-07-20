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
    // Runtime: 44 ms, faster than 94.90%
    // Memory Usage: 11.4 MB, less than 89.23%
    void setZeroes(vector< vector<int> >& matrix) {
        if (matrix.size() == 0) return;
        int m = matrix.size(), n = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstCol = true;
            }
        }

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRow = true;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < matrix.size(); i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstCol) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
        if (firstRow) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

int main(int argc, char ** argv) {

    // vector< vector<int> > mat = {
    //     {1, 1, 1},
    //     {1, 0, 1},
    //     {1, 1, 1}
    // };

    vector< vector<int> > mat = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    // vector< vector<int> > mat = {
    //     {1,1,1},
    //     {0,1,2}
    // };

    // vector< vector<int> > mat = {
    //     {1,0,3}
    // };

    Solution().setZeroes(mat);

    printMatrix(mat);

    return 0;
}