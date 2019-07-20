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
// Runtime: 4 ms, faster than 73.78% 
// Memory Usage: 8.5 MB, less than 77.45%
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> arr;
        int m = matrix.size() - 1;
        if (matrix.size() == 0) return arr;
        int n = matrix[0].size() - 1;

        int k = 0;

        while (k < min(m / 2, n / 2)) {
            //top
            for (int i = k; i < n - k; i++) {
                arr.push_back(matrix[k][i]);
            }
            //right
            for (int i = k; i < m - k; i++) {
                arr.push_back(matrix[i][n-k]);
            }
            //bottom
            for (int i = n-k; i > k; i--) {
                arr.push_back(matrix[m-k][i]);
            }
            //left
            for (int i = m-k; i > k; i--) {
                arr.push_back(matrix[i][k]);
            }
            
            k++;
            // printVector(arr);
        }

        
        if (m >= n) {
            if (n & 1) {
                arr.push_back(matrix[k][k]);
                for(int i = k; i <= m-k; i++) {
                    arr.push_back(matrix[i][k+1]);
                }
                for (int i = m-k; i > k; i--) {
                    arr.push_back(matrix[i][k]);
                }
            }
            else {
                for (int i = k; i <= m-k; i++) {
                    arr.push_back(matrix[i][k]);
                }
            }
        }
        else {
            if (m & 1) {
                for (int i = k; i <= n-k; i++) {
                    arr.push_back(matrix[k][i]);
                }
                for (int i = n-k; i >= k; i--) {
                    arr.push_back(matrix[k+1][i]);
                }
            }
            else {
                for (int i = k; i <= n-k; i++) {
                    arr.push_back(matrix[k][i]);
                }
            }
        }


        return arr;
    }

};

int main(int argc, char ** argv) {

    // vector< vector<int> > matrix = {
    //     {1},
    // };

    // vector< vector<int> > matrix = {
    //     {1, 2},
    // };

    // vector< vector<int> > matrix = {
    //     {1},
    //     {4}
    // };

    // vector< vector<int> > matrix = {
    //     {1, 2},
    //     {4, 5}
    // };

    // vector< vector<int> > matrix = {
    //     {1, 2, 3},
    //     {4, 5, 6}
    // };

    // vector< vector<int> > matrix = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };

    // vector< vector<int> > matrix = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12}
    // };

    // vector< vector<int> > matrix = {
    //     {1, 2, 3, 4, 5, 6},
    //     {7, 8, 9, 10, 11, 12},
    // };

    vector< vector<int> > matrix = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };

    // vector< vector<int> > matrix = {
    //     {1, 2, 3, 4, 5, 6},
    //     {7, 8, 9, 10, 11, 12},
    //     {13, 14, 15, 16, 17, 18},
    //     {19, 20, 21, 22, 23, 24},
    // };

    // vector< vector<int> > matrix = {
    //     {1, 2, 3, 4, 5, 6},
    //     {7, 8, 9, 10, 11, 12},
    //     {13, 14, 15, 16, 17, 18},
    //     {19, 20, 21, 22, 23, 24},
    //     {19, 20, 21, 22, 23, 24},
    // };

    // vector< vector<int> > matrix = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9},
    //     {10, 11, 12},
    //     {13, 14, 15},
    //     {16, 17, 18}
    // };

    // vector< vector<int> > matrix = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12},
    //     {13, 14, 15, 16}
    // };

    // vector< vector<int> > matrix = {
    //     {1, 2, 3, 4, 5},
    //     {6, 7, 8, 9, 10},
    //     {11, 12, 13, 14, 15},
    //     {16, 17, 18, 19, 20},
    //     {21, 22, 23, 24, 25},
    // };

    // vector< vector<int> > matrix = {
    //     {1, 2, 3, 8, 8},
    //     {4, 5, 6, 9, 9},
    //     {7, 8, 9, 1, 2},
    //     {10, 11, 12, 3, 4},
    //     {13, 14, 15, 5, 6},
    //     {16, 17, 18, 7 ,8}
    // };


    // vector< vector<int> > matrix = {
    //     {1, 2, 3, 8},
    //     {4, 5, 6, 9},
    //     {7, 8, 9, 1},
    //     {10, 11, 12, 3},
    //     {13, 14, 15, 5},
    //     {16, 17, 18, 7}
    // };

    printVector(Solution().spiralOrder(matrix));

    return 0;
}