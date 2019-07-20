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
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > p;
        vector<int> cur;
        helper(p, cur, nums);
        return p;
    }

    // void helper(vector< vector<int> > &p, vector<int> cur, vector<int> r) {
    //     // if (r.empty()) {
    //     //     p.push_back(cur);
    //     // }

    //     for (int i = 0; i < r.size(); i++) {
    //         cur.push_back(r[i]);
    //         int t = r[i];
    //         r.erase(r.begin() + i);
    //         if (!r.empty()) {
    //             helper(p, cur, r);
    //         }
    //         else {
    //             p.push_back(cur);
    //             return;
    //         }
    //         r.insert(r.begin() + i, t);
    //         cur.pop_back();
    //     }
    // }

    void helper(vector< vector<int> > &p, vector<int> &cur, const vector<int> &nums) {
        if (cur.size() == nums.size()) {
            p.push_back(cur);
        }

        for (int i = 0; i < nums.size(); i++) {
            //Notice given input is distinct
            if (find(cur.begin(), cur.end(), nums[i]) != cur.end()) {
                continue;
            } 
            cur.push_back(nums[i]);
            helper(p, cur, nums);
            cur.pop_back();

        }
    }

    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector< vector<int> > p;

    //     stack< vector<int> > r;
    //     stack< vector<int> > curs;
    //     r.push(nums);
    //     curs.push(vector<int>());

    //     while (!r.empty()) {
    //         vector<int> t = r.top();
    //         vector<int> cur = curs.top();
    //         r.pop();
    //         curs.pop();

    //         for (int i = 0; i < t.size(); i++) {
    //             cur.push_back(t[i]);
    //             int tmp = t[i];
    //             t.erase(t.begin() + i);
    //             if (!t.empty()) {
    //                 r.push(t);
    //                 curs.push(cur);
    //             }
    //             else {
    //                 p.push_back(cur);
    //             }
    //             t.insert(t.begin() + i, tmp);
    //             cur.pop_back();
    //         }
    //     }

    //     return p;
    // }
};

int main(int argc, char ** argv) {

    vector<int> v = {1, 2, 3};

    printMatrix(Solution().permute(v));

    return 0;
}