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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // recursive(res, root);
        iterative(res, root);
        return res;
    }

    // void recursive(vector<int> &res, TreeNode *c) {
    //     if (!c) {
    //         return;
    //     }

    //     recursive(res, c->left);
    //     res.push_back(c->val);
    //     recursive(res, c->right);
    // }

    void iterative(vector<int> &res, TreeNode *r) {
        
        stack<TreeNode*> stk;

        TreeNode *c = r;
        while (c || !stk.empty()) {
            if (c) {
                stk.push(c);
                c = c->left;
            }
            else {
                c = stk.top();
                stk.pop();
                res.push_back(c->val);
                c = c->right;
            }
   
            // cout << c-> val << endl;
            // printVector(res);
        }
    }
};
int main(int argc, char ** argv) {

    TreeNode *r = new TreeNode(1, 0, 2);
    r->right = new TreeNode(2, 1, 2);
    r->right->left = new TreeNode(3, 2, 2);

    printTree(r);

    printVector(Solution().inorderTraversal(r));

    return 0;
}