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
    // Runtime: 0 ms, faster than 100.00%
    // Memory Usage: 13.4 MB, less than 85.19%
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > ans;
        if (!root) return ans;
        stack<TreeNode*> s1, s2;

        s1.emplace(root);
        int level = 0;
        while (!s1.empty() || !s2.empty()) {
            ans.emplace_back(vector<int>());
            if (!(level&1)) {
                while (!s1.empty()) {
                    TreeNode *top = s1.top();
                    ans[level].emplace_back(top->val);
                    s1.pop();
                    if (top->left)
                        s2.emplace(top->left);
                    if (top->right)
                        s2.emplace(top->right);
                }
            }
            else {
                while (!s2.empty()) {
                    TreeNode *top = s2.top();
                    ans[level].emplace_back(top->val);
                    s2.pop();
                    if (top->right)
                        s1.emplace(top->right);
                    if (top->left)
                        s1.emplace(top->left);
                }
            }
            level++;
        }
        return ans;
    }
};

int main(int argc, char ** argv) {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    printMatrix(Solution().zigzagLevelOrder(root));

    return 0;
}