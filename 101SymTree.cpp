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

    // A tree is symmetric when the
    // tree is devided into two subtrees,
    // these two parts are mirror of each other.

    // Two subtrees are mirror of each other when:
    // 1. the root of the two symmetric subtrees are the same.
    // 2. the left subtree of the first tree is 
        // the mirror of the right subtree of the second tree
    // 3. the right subtree of the first tree is
        // the mirror of the left subtree of the second tree.
    // 4ms
    bool isMirror(TreeNode* l, TreeNode* r) {
        if (!l && !r) return true;
        else if ((l && !r) || (!l && r)) return false;

        return (l->val == r->val) && isMirror(l->left, r->right) 
            && isMirror(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {

        return isMirror(root, root);

    }
};

int main() {

    TreeNode* s = new TreeNode(1);
    s->left = new TreeNode(2);
    s->right = new TreeNode(2);
    // s->left->left = new TreeNode(4);
    s->left->right = new TreeNode(3);
    s->right->left = new TreeNode(3);
    // s->right->right = new TreeNode(4);

    Solution st;
    cout << st.isSymmetric(s) << endl;

    return 0;
}