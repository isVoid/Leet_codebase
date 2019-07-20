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
class NumMatrix {
public:

    vector< vector<int> > M;
    
    NumMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            vector<int> r;
            for (int j = 0; j < matrix[i].size(); j++) {
                r.push_back(matrix[i][j]);
            }
            M.push_back(r);
        }

        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[i].size(); j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                else if (i == 0) {
                    M[i][j] = M[i][j-1] + M[i][j];
                }
                else if (j == 0) {
                    M[i][j] = M[i-1][j] + M[i][j];
                }
                else {
                    M[i][j] = M[i-1][j] + M[i][j-1] - M[i-1][j-1] + M[i][j];
                }
            }
        }

        //debug
        // printMatrix(M, "\t");   
    }
    
    //32ms 47.08%
    //17.3MB 5.11%
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 > 0 && col1 > 0)
            return M[row2][col2] - M[row1-1][col2] - M[row2][col1-1] + M[row1-1][col1-1];
        else if (row1 > 0)
            return M[row2][col2] - M[row1-1][col2];
        else if (col1 > 0)
            return M[row2][col2] - M[row2][col1-1];
        else
            return M[row2][col2];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(int argc, char ** argv) {

    vector< vector<int> > matrix = 
    {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2 ,1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    // int row1 = 2, col1 = 1, row2 = 4, col2 = 3;
    // int row1 = 1, col1 = 1, row2 = 2, col2 = 2;
    // int row1 = 1, col1 = 2, row2 = 2, col2 = 4;
    // int row1 = 1, col1 = 0, row2 = 2, col2 = 1;
    // int row1 = 0, col1 = 2, row2 = 1, col2 = 3;
    int row1 = 0, col1 = 0, row2 = 0, col2 = 0;

    NumMatrix* obj = new NumMatrix(matrix);
    int param_1 = obj->sumRegion(row1,col1,row2,col2);

    cout << param_1 << endl;

    return 0;
}