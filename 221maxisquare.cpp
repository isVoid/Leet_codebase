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

    //16ms 97.89%
    //12.3MB 6.33%
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector< vector<int> > maxsq;
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            vector<int> x;
            if (matrix[i][0] == '0')
                x.push_back(0);
            else {
                x.push_back(1);
                ans = 1;
            }
                

            maxsq.push_back(x);
        }
        for (int i = 1; i < matrix[0].size(); i++) {
            if (matrix[0][i] == '0')
                maxsq[0].push_back(0);
            else {
                maxsq[0].push_back(1);
                ans = 1;
            }
                
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    maxsq[i].push_back(min(min(maxsq[i-1][j], maxsq[i][j-1]), maxsq[i-1][j-1]) + 1);
                }
                else {
                    maxsq[i].push_back(0);
                }
                ans = max(ans, maxsq[i][j]);
            }
        }

        printMatrix(maxsq);

        return ans * ans;
    }
};

int main(int argc, char ** argv) {

    // vector<char> v1 = {'1', '0', '1', '0', '0'};
    // vector<char> v2 = {'1', '0', '1', '1', '1'};
    // vector<char> v3 = {'1', '1', '1', '1', '1'};
    // vector<char> v4 = {'1', '0', '0', '1', '0'};

    // vector<char> v1 = {'1', '1', '1', '0', '0'};
    // vector<char> v2 = {'1', '1', '1', '1', '1'};
    // vector<char> v3 = {'1', '1', '1', '1', '1'};
    // vector<char> v4 = {'1', '0', '0', '1', '0'};

    // vector<char> v1 = {'0', '0', '0', '0', '0'};
    // vector<char> v2 = {'0', '0', '0', '0', '0'};
    // vector<char> v3 = {'0', '0', '0', '0', '0'};
    // vector<char> v4 = {'0', '0', '0', '0', '0'};

    // vector<char> v1 = {'0', '0', '0', '0', '0'};
    
    // vector<char> v1 = {'0'};
    // vector<char> v2 = {'0'};
    // vector<char> v3 = {'0'};
    // vector<char> v4 = {'0'};

    // vector<char> v1 = {'1'};
    // vector<char> v1 = {'1', '1', '1', '1'};

    // vector<char> v1 = {'0','1','1','0','1'};
    // vector<char> v2 = {'1','1','0','1','0'};
    // vector<char> v3 = {'0','1','1','1','0'};
    // vector<char> v4 = {'1','1','1','1','0'};
    // vector<char> v5 = {'1','1','1','1','1'};
    // vector<char> v6 = {'0','0','0','0','0'};

    // [["0","0","0","1"],["1","1","0","1"],["1","1","1","1"],["0","1","1","1"],["0","1","1","1"]]
    vector<char> v1 = {'0', '0', '0', '1'};
    vector<char> v2 = {'1', '1', '0', '1'};
    vector<char> v3 = {'1', '1', '1', '1'};
    vector<char> v4 = {'0', '1', '1', '1'};
    vector<char> v5 = {'0', '1', '1', '1'};

    vector< vector<char> > vv = {v1, v2, v3, v4, v5};

    // printMatrix(vv);

    cout << Solution().maximalSquare(vv) << endl;

    return 0;
}