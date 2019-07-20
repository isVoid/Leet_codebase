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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //24ms 73.95%
    //17.6MB 9.44%
    vector<TreeNode*> helper(int a, int b) {
        vector<TreeNode*> ans;
        if (a > b) {
            ans.push_back(nullptr);
            return ans;
        }

        for (int i = a; i <= b; i++) {
            vector<TreeNode*> leftTrees = helper(a, i - 1);
            vector<TreeNode*> rightTrees = helper(i+1, b);
            for (TreeNode* l : leftTrees) {
                for (TreeNode* r : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return helper(1, n);
    }
};
int main(int argc, char ** argv) {

    vector<TreeNode*> ans = Solution().generateTrees(0);
    cout << ans.size() << endl;

    for (TreeNode* r : ans) {
        printTree(r);
    }

    return 0;
}