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
    bool isValidSudoku(vector<vector<char>>& board) {

        bool rowUsed[10][10] = {0}, 
            colUsed[10][10] = {0}, 
            blockUsed[10][10] = {0};
        //Check row
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                else if (board[i][j] >= '0' && board[i][j] <= '9' && !rowUsed[i][board[i][j] - '0']) {
                    rowUsed[i][board[i][j] - '0'] = true;
                }
                else {
                    cout << "Fail with row check" << endl;
                    return false;
                }
            }
        }

        //Check col
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') {
                    continue;
                }
                else if (board[i][j] >= '0' && board[i][j] <= '9' && !colUsed[j][board[i][j] - '0']) {
                    colUsed[j][board[i][j] - '0'] = true;
                }
                else {
                    cout << "Fail with col check" << endl;
                    return false;
                }
            }
        }

        //Check 3x3
        #define B(a, b, i, j) board[a * 3 + i][b * 3 + j]
        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++) {
                int idx = a * 3 + b;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (B(a, b, i, j) == '.') {
                            continue;
                        }
                        else if (B(a, b, i, j) >= '0' && B(a, b, i, j) <= '9' && !blockUsed[idx][B(a, b, i, j) - '0']) {
                            blockUsed[idx][B(a, b, i, j) - '0'] = true;
                        }
                        else {
                            cout << "Fail with 3x3 check" << endl;
                            return false;
                        }
                    }
                }
            }

        return true;
    }
};

int main(int argc, char ** argv) {

    // vector< vector<char> > b = {
    //     {'5','3','.','.','7','.','.','.','.'},
    //     {'6','.','.','1','9','5','.','.','.'},
    //     {'.','9','8','.','.','.','.','6','.'},
    //     {'8','.','.','.','6','.','.','.','3'},
    //     {'4','.','.','8','.','3','.','.','1'},
    //     {'7','.','.','.','2','.','.','.','6'},
    //     {'.','6','.','.','.','.','2','8','.'},
    //     {'.','.','.','4','1','9','.','.','5'},
    //     {'.','.','.','.','8','.','.','7','9'}  
    // };

    vector< vector<char> > b = {
        {'5','3','9','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}  
    };

    // vector< vector<char> > b = {
    //     {'5','3','.','.','7','.','.','.','.'},
    //     {'6','.','.','1','9','5','.','.','.'},
    //     {'.','9','8','.','.','.','.','6','.'},
    //     {'8','.','.','.','6','.','.','.','3'},
    //     {'4','.','.','8','.','3','.','.','1'},
    //     {'7','.','.','.','2','.','.','.','6'},
    //     {'.','6','.','.','.','.','2','8','.'},
    //     {'.','.','.','4','1','9','.','.','5'},
    //     {'.','.','6','.','8','.','.','7','9'}  
    // };




    cout << Solution().isValidSudoku(b) << endl;

    return 0;
}