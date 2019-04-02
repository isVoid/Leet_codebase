#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    // Recursive Build Tree Note: when pointer passed
    // into function, what's being pointed to can be modded,
    // while pointer itself cannot.
    TreeNode* BuildTree(int a, int b, vector<int>& nums) {
        if (a > b) {
            return NULL;
        }
        int c = (a+b) / 2;
        cout << a << " " << b << " " << c << " " << nums[c] << endl;
        TreeNode* r = new TreeNode(nums[c]);
        cout << r << endl;
        r->left = BuildTree(a, c-1, nums);
        r->right = BuildTree(c+1, b, nums);

        return r;
    }

    // 8ms 100%
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        root = BuildTree(0, nums.size()-1, nums);
        return root;
    }
};

void dfs(TreeNode* r, int l = 0) {
    if (!r) return;
    cout << l << " " << r->val << " ";
    l++;
    dfs(r->left, l);
    dfs(r->right, l);
}

int main() {

    vector<int> v;
    v.push_back(-10);
    v.push_back(-3);
    v.push_back(0);
    v.push_back(5);
    v.push_back(9);
    v.push_back(100);
    v.push_back(101);

    Solution s;
    TreeNode* r = s.sortedArrayToBST(v);

    dfs(r);
    cout << endl;

    return 0;
}