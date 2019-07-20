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
    //8ms 75.35%
    //9MB 84.02%
    // vector< vector<int> > subsets(vector<int>& nums) {
    //     vector< vector<int> > ss = {}; //empty set
    //     vector<int> cur;
    //     helper(ss, cur, nums, 0);
    //     return ss;
    // }
    // void helper(vector< vector<int> > &ss, vector<int> &cur, vector<int> &nums, int index) {
    //     ss.push_back(cur);

    //     for (int i = index; i < nums.size(); i++) {
    //         cur.push_back(nums[i]);
    //         helper(ss, cur, nums, i+1);
    //         cur.pop_back();
    //     }
    // }

    //4ms 98.77%
    //9.3MB 34.90%
    vector< vector<int> > subsets(vector<int>& nums) {
        vector< vector<int> > ss = {}; //empty set
        bitset<32> b;
        unsigned long n = pow(2, nums.size());
        for (unsigned long i = 0; i < n; i++) {
            b = bitset<32>(i);
            vector<int> subset;
            for (int j = 0; j < nums.size(); j++) {
                if (b.test(j)) {
                    subset.push_back(nums[j]);
                }
            }
            ss.push_back(subset);
        }

        return ss;
    }
};

int main(int argc, char ** argv) {

    // vector<int> n = {1, 2 ,3};
    vector<int> n = {1, 2 ,3, 4};

    printMatrix(Solution().subsets(n));

    return 0;
}