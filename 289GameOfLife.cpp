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

#define isLive(i, j) (board[i][j] == LIVE || board[i][j] == LIVE_DEAD || board[i][j] == LIVE_LIVE)
#define isDead(i, j) (board[i][j] == DEAD || board[i][j] == DEAD_LIVE || board[i][j] == DEAD_LIVE)
#define willLive(i, j) (board[i][j] == LIVE || board[i][j] == DEAD_LIVE || board[i][j] == LIVE_LIVE)
class Solution {
public:

    const int DEAD = 0, LIVE = 1;
    const int DEAD_DEAD = 2, DEAD_LIVE = 3, LIVE_DEAD = 4, LIVE_LIVE = 5;

    int countLiveNeighbor(vector<vector<int>>& board, int i, int j) {

        int num = 0;
        for (int a = -1; a <= 1; a++) {
            for (int b = -1; b <= 1; b++) {
                if (a == 0 && b == 0) continue;
                if (i + a >= 0 && i + a < board.size() && 
                    j + b >= 0 && j + b < board[i].size() &&
                    isLive(i+a, j+b)) {
                        num++;
                    }
            }
        }
        return num;
    }

    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int livingNeighbor = countLiveNeighbor(board, i, j);

                if (board[i][j] == LIVE) {
                    if (livingNeighbor < 2) {
                        board[i][j] = LIVE_DEAD;
                    }
                    else if (livingNeighbor == 2 || livingNeighbor == 3) {
                        board[i][j] = LIVE_LIVE;
                    }
                    else {
                        board[i][j] = LIVE_DEAD;
                    }
                }
                else {
                    if (livingNeighbor == 3) {
                        board[i][j] = DEAD_LIVE;
                    }
                }
            }
        }

        printMatrix(board);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                board[i][j] = willLive(i, j);
            }
        }

    }
};

int main(int argc, char ** argv) {

    vector< vector<int> > test = {
        {1, 0, 0, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1, 0, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 1, 0, 0, 0, 1, 1, 0},
        {1, 1, 0, 0, 1, 1, 0, 0}
    };

    // cout << Solution().countLiveNeighbor(test, 0, 0) << endl;
    // cout << Solution().countLiveNeighbor(test, 4, 0) << endl;
    // cout << Solution().countLiveNeighbor(test, 3, 2) << endl;
    // cout << Solution().countLiveNeighbor(test, 2, 4) << endl;
    // cout << Solution().countLiveNeighbor(test, 1, 5) << endl;

    Solution().gameOfLife(test);

    printMatrix(test);

    return 0;
}