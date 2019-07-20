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
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector< vector<int> > cs;
        helper(cs, candidates, vector<int>(), target, 0);
        return cs;
    }

    //12ms 89.55%
    //10.7MB 51.32%
    void helper(vector< vector<int> > &combi, vector<int> &candi, vector<int> cur_combi, int target, int j) {
        if (target == 0) {
            combi.push_back(cur_combi);
            return;
        }
        else if (target < 0) {
            return;
        }

        for (int i = j; i < candi.size(); i++) {
            if (target >= candi[i]) {
                cur_combi.push_back(candi[i]);
                helper(combi, candi, cur_combi, target-candi[i], i);
                cur_combi.pop_back();
            }
        }
    }
    
};
int main(int argc, char ** argv) {

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    printMatrix(Solution().combinationSum(candidates, target));

    return 0;
}