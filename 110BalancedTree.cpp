#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    // 12ms 15.01%

    // Get Maximum Height
    // Count from bottom up
    int getMaximumHeight(TreeNode* r) {
        if (!r) {
            return 0;
        }

        return 1 + max(getMaximumHeight(r->left), getMaximumHeight(r->right));

    }

    // Recursive
    bool isBalanced(TreeNode* root) {
        // A null node is balanced
        if (!root) {
            return true;
        }

        // Get max height of left and right node
        int lh = getMaximumHeight(root->left);
        int rh = getMaximumHeight(root->right);

        // If max difference between left and right node less than 2
        // Proceed to verify subtrees of each node
        if (abs(lh - rh) < 2) {
            return isBalanced(root->left) && isBalanced(root->right);
        }
        // Otherwise not satisfied
        else {
            return false;
        }
    }

};

int main() {

    // TreeNode* s = new TreeNode(1);
    // s->left = new TreeNode(2);
    // s->right = new TreeNode(2);
    // // s->left->left = new TreeNode(4);
    // s->left->right = new TreeNode(3);
    // s->right->left = new TreeNode(3);
    // s->right->left->left = new TreeNode(3);
    // s->right->left->left->left = new TreeNode(3);
    // s->right->right = new TreeNode(4);

    // False
    // TreeNode* s = new TreeNode(1);
    // s->left = new TreeNode(2);
    // s->right = new TreeNode(2);
    // s->left->left = new TreeNode(3);
    // s->right->right = new TreeNode(3);
    // s->left->left->left = new TreeNode(4);
    // s->right->right->right = new TreeNode(4);


    // TreeNode* s = NULL;

    // TreeNode* s = new TreeNode(1);
    // s->left = new TreeNode(2);
    // s->left->left = new TreeNode(3);

    // TreeNode* s = new TreeNode(1);
    // s->left = new TreeNode(2);

    // TreeNode* s = new TreeNode(1);


    Solution st;
    cout << st.isBalanced(s) << endl;

    return 0;
}