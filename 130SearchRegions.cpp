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

    // Runtime: 28 ms, faster than 89.34% of C++ online submissions for Surrounded Regions.
    // Memory Usage: 14.1 MB, less than 64.37% of C++ online submissions for Surrounded Regions.
    void solve(vector< vector<char> >& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        stack< pair<int, int> > dfs;

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs.push({i, 0});
            if (board[i][n-1] == 'O')
                dfs.push({i, n-1});
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs.push({0, j});
            if (board[m-1][j] == 'O')
                dfs.push({m-1, j});
        }

        while (!dfs.empty()) {
            // int i = dfs.top().first, j = dfs.top().second;
            pair<int, int> t = dfs.top();
            int i = t.first, j = t.second;
            dfs.pop();
            board[i][j] = 'P';

            if (i > 0 && board[i-1][j] == 'O') {
                dfs.push({i-1, j});
            }
            if (j > 0 && board[i][j-1] == 'O') {
                dfs.push({i, j-1});
            }
            if (i < m-1 && board[i+1][j] == 'O') {
                dfs.push({i+1, j});
            }
            if (j < n-1 && board[i][j+1] == 'O') {
                dfs.push({i, j+1});
            }
        }

        for (auto &r : board)
            for (auto &c : r) {
                if (c == 'O') {
                    c = 'X';
                }
                else if (c == 'P') {
                    c = 'O';
                }
            }

    }
};

int main(int argc, char ** argv) {

    vector< vector<char> > board = {
        { 'X', 'X', 'X', 'X', 'X' },
        { 'X', 'O', 'X', 'O', 'X' },
        { 'X', 'O', 'X', 'O', 'X' },
        { 'X', 'X', 'O', 'O', 'X' },
        { 'X', 'X', 'O', 'X', 'X' },
    };

    Solution().solve(board);

    printMatrix(board);

    return 0;
}