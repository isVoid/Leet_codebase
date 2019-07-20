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
    // Runtime: 4 ms, faster than 97.53% 
    // Memory Usage: 8.5 MB, less than 82.67% 

    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int lo = 0, hi = nums.size()-1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            bool ascending;
            if (mid < nums.size()-1) {
                ascending = nums[mid] < nums[mid+1];
            }
            else {
                ascending = nums[mid-1] < nums[mid];
            }

            if (ascending) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        return min(lo, (int)nums.size()-1);
        
    }
};
int main(int argc, char ** argv) {

    // vector<int> seq = {1, 2, 1, 3, 5, 6, 4};
    // vector<int> seq = {1, 2, 1};
    // vector<int> seq = {1, 2, 1, 3, 2};
    // vector<int> seq = {1, 2, 3, 4, 5};
    // vector<int> seq = {5, 4, 3 ,2 ,1};
    // vector<int> seq = {1, 2, 3, -1, 0};
    vector<int> seq = {1};

    cout << Solution().findPeakElement(seq) << endl;

    return 0;
}