#include <iostream>
#include <vector>
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
    //Recurse
    //4ms 100%
    //9.1MB 67.79%
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            TreeNode *l = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(l);
        }
        return root;
    }
};

int main(int argc, char ** argv) {

    // /*
    // *
    // *       4
    // *   2       7
    // * nul   3   6   9
    // * 
    // * */

    // TreeNode *h = new TreeNode(4, 0, 2);
    // h->left = new TreeNode(2, 1);
    // h->right = new TreeNode(7, 1);
    // h->left->left = NULL;
    // h->left->right = new TreeNode(3, 2);
    // h->right->left = new TreeNode(6, 2);
    // h->right->right = new TreeNode(9, 2);

    // TreeNode *h = NULL;

    TreeNode *h = new TreeNode(1);

    printTree(h);
    Solution s;
    TreeNode *r = s.invertTree(h);
    cout << endl;
    printTree(r);

    return 0;
}