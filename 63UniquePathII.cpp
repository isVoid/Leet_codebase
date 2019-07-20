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

    // 8ms 40.51%
    // 9.9MB 5.04%
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector< vector<long> > grid;
        for (auto &v : obstacleGrid) {
            vector<long> r;
            for (auto &i : v) {
                if (i == 0)
                    r.push_back(i);
                else
                    r.push_back(-1);
            }
            grid.push_back(r);
        }

        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == -1 || grid[m-1][n-1] == -1) return 0;
        else grid[0][0] = 1;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == -1) continue;
    //             if (i == 0 && j == 0) continue;
    //             else if (i == 0) {
    //                 if (grid[i][j-1] == -1) grid[i][j] = -1;
    //                 else grid[i][j] = grid[i][j-1];
    //             }
    //             else if (j == 0) {
    //                 if (grid[i-1][j] == -1) grid[i][j] = -1;
    //                 else grid[i][j] = grid[i-1][j];
    //             }
    //             else {
    //                 if (grid[i-1][j] == -1 && grid[i][j-1] == -1) grid[i][j] = -1;
    //                 else if (grid[i-1][j] == -1) grid[i][j] = grid[i][j-1];
    //                 else if (grid[i][j-1] == -1) grid[i][j] = grid[i-1][j];
    //                 else grid[i][j] = grid[i-1][j] + grid[i][j-1];
    //             }
    //         }
    //     }

    //     return grid[m-1][n-1] != -1 ? grid[m-1][n-1] : 0;
    // }
};

int main(int argc, char ** argv) {

    vector<int> v1 = {0, 0, 0};
    vector<int> v2 = {0, 1, 0};
    vector<int> v3 = {0, 1, 0};
    vector<int> v4 = {0, 0, 0};

    vector< vector<int> > grid = {v1, v2, v3, v4};

    cout << Solution().uniquePathsWithObstacles(grid) << endl;

    return 0;
}