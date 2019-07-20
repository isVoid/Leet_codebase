#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
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

    //Runtime: 12 ms, faster than 94.17% of C++ online submissions for Number of Islands.
    // Memory Usage: 11.2 MB, less than 34.39% of C++ online submissions for Number of Islands.
    int numIslands(vector< vector<char> > & grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // printMatrix(grid);
                if (grid[i][j] == '1') {
                    cnt++;
                    grid[i][j] = '0';
                    search(grid, i, j);
                }
            }
        }
        return cnt;
    }
    void search(vector< vector<char> > &grid, int i, int j) {
        queue< pair<uint32_t, uint32_t> > bqueue;
        bqueue.emplace(make_pair(i, j));

        while (!bqueue.empty()) {
            // printMatrix(grid);
            pair<int, int> coord = bqueue.front();
            bqueue.pop();
            int x = coord.first, y = coord.second;
            // grid[x][y] = 'V';

            if (x > 0 && grid[x-1][y] == '1') {
                grid[x-1][y] = '0';
                bqueue.emplace(make_pair(x-1, y));
            }
            if (x < grid.size()-1 && grid[x+1][y] == '1') {
                grid[x+1][y] = '0';
                bqueue.emplace(make_pair(x+1, y));
            }
            if (y > 0 && grid[x][y-1] == '1') {
                grid[x][y-1] = '0';
                bqueue.emplace(make_pair(x, y-1));
            }
            if (y < grid[0].size()-1 && grid[x][y+1] == '1') {
                grid[x][y+1] = '0';
                bqueue.emplace(make_pair(x, y+1));
            }
        }
    }
};

int main(int argc, char ** argv) {

    // vector< vector<char> > grid = {
    //     {'1','1','1','1','0'},
    //     {'1','1','0','1','0'},
    //     {'1','1','0','0','0'},
    //     {'0','0','0','0','0'}
    // };

    // vector< vector<char> > grid = {
    //     {'1','1','0','0','0'},
    //     {'1','1','0','1','0'},
    //     {'0','0','0','0','0'},
    //     {'0','0','0','1','1'}
    // };

    vector< vector<char> > grid = {
        {'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},
        {'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},
        {'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
        {'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
        {'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},
        {'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
        {'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},
        {'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
    };

    cout << Solution().numIslands(grid) << endl;

    return 0;
}