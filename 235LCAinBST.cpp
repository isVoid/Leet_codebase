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

    //44ms 97.90
    //25.7MB 76.54
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root) return nullptr;

       if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else 
            return root;
    }
};

int main(int argc, char ** argv) {

    TreeNode *r = new TreeNode(6, 0, 3);
    r->left = new TreeNode(2, 1);
    r->right = new TreeNode(8, 1);
    r->left->left = new TreeNode(0, 2);
    r->left->right = new TreeNode(4, 2);
    r->right->left = new TreeNode(7, 2);
    r->right->right = new TreeNode(9, 2);
    r->left->right->left = new TreeNode(3, 3);
    r->left->right->right = new TreeNode(5, 3);

    Solution s;
    
    TreeNode *p = r->left->right->right;
    TreeNode *q = r->right->right;

    printTree(r);
    cout << p->val << " " << q->val << endl;

    cout << s.lowestCommonAncestor(r, p, q)->val << endl;

    return 0;
}