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
    //8ms 86.39%
    //8.6MB 60.53%
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i >= 1) {
            //Requires strictly smaller, otherwise we may be dealing with a flat sequence.
            if (nums[i-1] < nums[i]) {
                int j = i;
                //Has to be strictly larger, otherwise lexicographic order is unchanged.
                while (j < nums.size() && nums[j] > nums[i-1]) {
                    j++;
                }
                j = j-1;

                //swap
                int t = nums[i-1];
                nums[i-1] = nums[j];
                nums[j] = t;

                //reverse
                reverse(nums.begin() + i, nums.end());
                return;
            }
            i--;
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};

int main(int argc, char ** argv) {

    // vector<int> nums = {1, 2, 3};
    // vector<int> nums = {3, 2, 1};
    // vector<int> nums = {2, 1, 3};
    // vector<int> nums = {2, 3, 1};
    // vector<int> nums = {1, 5, 1};
    vector<int> nums = {5, 1, 1};
    Solution().nextPermutation(nums);

    printVector(nums);

    return 0;
}