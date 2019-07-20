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

    bool inputHelper(vector<string> &b, string w) {
        vector< vector<char> > brd;
        for (int i = 0; i < b.size(); i++) {
            vector<char> row;
            for (int j = 0; j < b[i].length(); j++) {
                row.push_back(b[i][j]);
            }
            brd.push_back(row);
        }
        printMatrix(brd);

        return exist(brd, w);
    }

    //12ms 99.80%
    //10.1MB 85.08%
    bool exist(vector< vector<char> >& board, string word) {
        if (word.length() == 0) {
            return true;
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    char tmp = board[i][j];
                    board[i][j] = 0;
                    if (helper(board, word, 1, i, j)) {
                        return true;
                    }
                    board[i][j] = tmp;
                }
            }
        }

        return false;
    }

    bool helper(vector< vector<char> > &board, string &word, int index, int i, int j) {

        if (index == word.size()) {
            return true;
        }

        char tmp;
        if (i >= 1 && board[i-1][j] != 0 && board[i-1][j] == word[index]) {
            tmp = board[i-1][j];
            board[i-1][j] = 0;
            if (helper(board, word, index+1, i-1, j)) {
                return true;
            }
            board[i-1][j] = tmp;
        }

        if (j >= 1 && board[i][j-1] != 0 && board[i][j-1] == word[index]) {
            tmp = board[i][j-1];
            board[i][j-1] = 0;
            if (helper(board, word, index+1, i, j-1)) {
                return true;
            }
            board[i][j-1] = tmp;
        }

        if (i < board.size()-1 && board[i+1][j] != 0 && board[i+1][j] == word[index]) {
            tmp = board[i+1][j];
            board[i+1][j] = 0;
            if (helper(board, word, index+1, i+1, j)) {
                return true;
            }
            board[i+1][j] = tmp;
        }

        if (j < board[0].size()-1 && board[i][j+1] != 0 && board[i][j+1] == word[index]) {
            tmp = board[i][j+1];
            board[i][j+1] = 0;
            if (helper(board, word, index+1, i, j+1)) {
                return true;
            }
            board[i][j+1] = tmp;
        }

        return false;
    }
};

int main(int argc, char ** argv) {

    vector<string> board = {
        "ABCE",
        "SFCS",
        "ADEE"
    };
    // string word = "ABCCED";
    // string word = "SEE";
    string word = "ABCB";

    cout << Solution().inputHelper(board, word) << endl;

    return 0;
}