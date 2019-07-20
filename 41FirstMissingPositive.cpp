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
    int firstMissingPositive(vector<int>& nums) {

        // if (nums.size() == 1) {
        //     if (nums[0] == 1) return 2;
        //     else return 1;
        // }

        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != i+1 && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        printVector(nums);

        int i = 0;
        for (; i < nums.size(); i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return i+1;
    }
};
int main(int argc, char ** argv) {

    // vector<int> v = {1, 2, 0};
    // vector<int> v = {3, 4, -1, 1};
    vector<int> v = {1};
    // vector<int> v = {1, 1};
    // vector<int> v = {2, 1};

    cout << Solution().firstMissingPositive(v) << endl;

    return 0;
}