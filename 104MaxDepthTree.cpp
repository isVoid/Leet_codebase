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

    void dfs(TreeNode* r, int d, int& maxd) {
        if (!r) {
            return;
        }

        if (d > maxd) {
            maxd = d;
        }
        d++;
        dfs(r->left, d, maxd);
        dfs(r->right, d, maxd);
        
    }

    int maxDepth(TreeNode* root) {
        int maxd = 0;
        dfs(root, 1, maxd);
        return maxd;
    }
};

int main() {

    TreeNode* s = new TreeNode(1);
    s->left = new TreeNode(2);
    s->right = new TreeNode(2);
    // s->left->left = new TreeNode(4);
    s->left->right = new TreeNode(3);
    s->right->left = new TreeNode(3);
    s->right->left->left = new TreeNode(4);
    // s->right->right = new TreeNode(4);

    Solution st;
    cout << st.maxDepth(s) << endl;

    return 0;
}