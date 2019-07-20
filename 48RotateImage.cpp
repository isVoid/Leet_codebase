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

    //Rim solution
    //4ms 89.87%
    //9MB 60.75%
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        //kth rim from outer
        int k = 0;
        while (k <= n / 2) {
            //the length of kth rim is n-2k
            for (int i = 0; i < n-k * 2; i++) {
                
                int t;
                int t2;

                //top rim to right rim
                t = matrix[k+i][n-k];
                matrix[k+i][n-k] = matrix[k][k+i];

                //right rim to bottom rim
                t2 = matrix[n-k][n-k-i];
                matrix[n-k][n-k-i] = t; 
                
                //bottom rim to left rim
                t = matrix[n-k-i][k];
                matrix[n-k-i][k] = t2;

                //left rim to top rim
                matrix[k][k+i] = t;
            }
            //step inside
            k++;
        }
    }
};

int main(int argc, char ** argv) {

    // vector< vector<int> > img = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };
    // vector< vector<int> > img = {
    //     {1, 3},
    //     {7, 9}
    // };

    // vector< vector<int> > img = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12},
    //     {13, 14, 15, 16}
    // };

    // vector< vector<int> > img = {
    //     {1}
    // };

    vector< vector<int> > img = {
    };

    Solution().rotate(img);

    printMatrix(img);

    return 0;
}