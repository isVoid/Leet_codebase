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

    //93.57% 12ms
    //20.6MB 57.82%
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return helper(root->left, LONG_MIN, root->val) && helper(root->right, root->val, LONG_MAX);
    }

    bool helper(TreeNode *root, long mini, long maxi) {
        if (!root) return true;

        bool f = root->val > mini && root->val < maxi;

        if (root->left) {
            f = f && helper(root->left, mini, min(maxi, (long)root->val));
        }

        if (root->right) {
            f = f && helper(root->right, max(mini, (long)root->val), maxi);
        }

        return f;
        
    }

    
};

int main(int argc, char ** argv) {

    /**
     *          5
     *      1        4
     *             3   6
     */

    TreeNode *r = new TreeNode(5);
    r->left = new TreeNode(1);
    r->right = new TreeNode(4);
    r->right->left = new TreeNode(3);
    r->right->right = new TreeNode(6);


    /**
     *          2
     *      1       3
     */

    // TreeNode *r = new TreeNode(2);
    // r->left = new TreeNode(1);
    // r->right = new TreeNode(4);


    // TreeNode *r = new TreeNode(10);
    // r->left = new TreeNode(5);
    // r->right = new TreeNode(15);
    // r->right->left = new TreeNode(6);
    // r->right->right = new TreeNode(20);


    cout << Solution().isValidBST(r) << endl;

    return 0;
}