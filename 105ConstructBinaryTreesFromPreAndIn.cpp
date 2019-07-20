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
    // Runtime: 16 ms, faster than 88.21%
    // Memory Usage: 17.2 MB, less than 39.57%
    unordered_map<int, int> m;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            m.insert(make_pair(inorder[i], i));
        }

        TreeNode *r;
        r = helper(preorder, inorder, 0, 0, inorder.size());
        return r;
    }

    TreeNode* helper(vector<int> &preorder, vector<int> &inorder, int pre, int in1, int in2) {
        if (pre == preorder.size() || in1 > in2) {
            return nullptr;
        }

        TreeNode *c = new TreeNode(preorder[pre]);

        int i = m[preorder[pre]];
        c->left = helper(preorder, inorder, pre + 1, in1, i-1);
        c->right = helper(preorder, inorder, pre + i - in1 + 1, i+1, in2);

        return c;
    }
};

int main(int argc, char ** argv) {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *r = Solution().buildTree(preorder, inorder);

    cout << r->val << endl;
    printTree(r);

    return 0;
}