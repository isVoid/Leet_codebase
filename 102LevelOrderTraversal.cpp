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

    //8ms 75.51%
    //13.8MB 71.52%
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > res;
        vector<int> cur_level_nodes;

        queue< pair<int, TreeNode*> > q;
        q.push(make_pair(0, root));
        int cur_level = 0;
        int level = 0;
        

        while (!q.empty()) {

            level = q.front().first;
            TreeNode *c = q.front().second;
            q.pop();

                        
            if (level > cur_level) {
                cur_level = level;
                // printVector(cur_level_nodes);
                res.push_back(cur_level_nodes);
                cur_level_nodes.clear();
            }

            if (c) {
                cur_level_nodes.push_back(c->val);
                q.push(make_pair(level+1, c->left));
                q.push(make_pair(level+1, c->right));
            }
        }

        return res;

    }
};
int main(int argc, char ** argv) {

    TreeNode *r = new TreeNode(3);
    r->left = new TreeNode(9);
    r->right = new TreeNode(20);
    r->right->left = new TreeNode(15);
    r->right->right = new TreeNode(7);

    printMatrix(Solution().levelOrder(r));

    return 0;
}