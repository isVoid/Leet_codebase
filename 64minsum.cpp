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
    //12ms 97.87%
    //10.5MB 100.0%
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                else if (i == 0) grid[i][j] = grid[i][j-1] + grid[i][j];
                else if (j == 0) grid[i][j] = grid[i-1][j] + grid[i][j];
                else grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[m-1][n-1];
    }
};

int main(int argc, char ** argv) {

    vector<int> v0 = {1, 3, 1};
    vector<int> v1 = {1, 5, 1};
    vector<int> v2 = {4, 2, 1};

    vector< vector<int> > g = {v0, v1, v2};

    int d = Solution().minPathSum(g);

    cout << d << endl;

    return 0;
}