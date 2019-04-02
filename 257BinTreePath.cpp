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

    // 8ms 99.61%
    // 13MB 26.16%
    
    vector<string> r;
    int curSubTree = 0; //0 for left, 1 for right
    void dfs(TreeNode *path, string sPath) {
        if (path == nullptr) {
            return;
        }
        sPath = sPath + "->" + to_string(path->val);

        if (path->left == nullptr &&
        path->right == nullptr) {
            r.push_back(sPath);
        }
        dfs(path->left, sPath);
        dfs(path->right, sPath);
        return;
    }

    vector<string> binaryTreePaths(TreeNode* path) {
        dfs(path, "");
        for (auto &rs : r) {
            rs.erase(0, 2);
        }
        return r;
    }
};

int main(int argc, char ** argv) {

    //1->2->4 1->2->5 1->3
    TreeNode *r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->left->left = new TreeNode(4);
    r->left->right = new TreeNode(5);

    //1
    TreeNode *r2 = new TreeNode(1);

    //null tree
    TreeNode *r3 = nullptr;

    Solution s;
    vector<string> ans = s.binaryTreePaths(r3);

    printVector(ans);

    return 0;
}