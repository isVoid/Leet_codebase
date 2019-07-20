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

// Runtime: 4 ms, faster than 81.87% of C++ online submissions for Sort Colors.
// Memory Usage: 8.5 MB, less than 76.28% of C++ online submissions for Sort Colors.

// Notice, when swapping 2, i is not incremented
// Since anything before i is either 0 or 1, anything after i can be 0, 1 or 2.
// We don't know what is being swapped so need to make a "second look", if 
// 2 is swapped to position i, we need to swap once more.
    void sortColors(vector<int>& nums) {
       int front = -1, back = nums.size();
       int i = 0;
       while (i < back) {
           if (nums[i] == 0) {
               swap(nums[i++], nums[++front]);
           }
           else if (nums[i] == 2) {
               swap(nums[i], nums[--back]);
           }
           else {
               i++;
           }
       }
    }
};

int main(int argc, char ** argv) {

    vector<int> n = {2, 0, 2, 1, 1, 0};
    // vector<int> n = {1, 1, 2, 2, 0, 0};
    // vector<int> n = {0, 1};
    // vector<int> n = {0, 2, 1};

    Solution().sortColors(n);

    printVector(n);

    return 0;
}