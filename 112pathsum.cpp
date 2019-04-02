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

    // 4ms 100%
    vector<int> ds;
    void dfs(TreeNode* r, int s) {
        if (!r) {
            return;
        }
        s = s + r->val;
        // leaf
        if (!r->left && !r->right) {
            ds.push_back(s);            
        }
        dfs(r->left, s);
        dfs(r->right, s);
    }


    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        dfs(root, 0);
        for (auto i:ds) {
            if (i == sum) return true;
        }
        return false;
    }

};

int main() {

    TreeNode* s = new TreeNode(1);
    s->left = new TreeNode(2);
    s->right = new TreeNode(2);
    // s->left->left = new TreeNode(4);
    // s->left->right = new TreeNode(3);
    s->right->left = new TreeNode(3);
    s->right->left->left = new TreeNode(3);
    s->right->left->left->left = new TreeNode(3);
    s->right->right = new TreeNode(4);

    // TreeNode* s = new TreeNode(1);
    // s->left = new TreeNode(2);
    // s->right = new TreeNode(2);
    // s->left->left = new TreeNode(3);
    // s->right->right = new TreeNode(3);
    // s->right->left = new TreeNode(3);
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
    cout << st.hasPathSum(s, 12) << endl;

    return 0;
}