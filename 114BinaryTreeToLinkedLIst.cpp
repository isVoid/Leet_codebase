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
    
    // Runtime: 4 ms, faster than 95.95%
    // Memory Usage: 9.4 MB, less than 99.81%
    TreeNode *prev = nullptr;
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

int main(int argc, char ** argv) {

    TreeNode *root = new TreeNode(5);

    return 0;
}