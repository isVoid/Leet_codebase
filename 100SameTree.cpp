#include <iostream>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 0ms 100
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pQ, qQ;
        pQ.push(p);
        qQ.push(q);
        while(!pQ.empty() && !qQ.empty()) {
            p = pQ.front();
            q = qQ.front();
            pQ.pop();
            qQ.pop();

            if ((p && !q) || (!p && q)) {
                return false;
            }

            if (!p && !q) {
                continue;
            }

            if (p->val != q->val) {
                return false;
            }

            pQ.push(p->left);
            pQ.push(p->right);
            qQ.push(q->left);
            qQ.push(q->right);

        }

        return true;
    }
};

int main() {

    TreeNode *a = new TreeNode(1);
    // a->left = new TreeNode(2);
    a->left = new TreeNode(3);
    a->right = new TreeNode(3);

    TreeNode *b = new TreeNode(1);
    // b->left = new TreeNode(2);
    b->right = new TreeNode(2);
    b->right->right = new TreeNode(3);
    

    Solution s;
    cout << s.isSameTree(a, b) << endl;

    return 0;
}