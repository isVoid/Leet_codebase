#include <iostream>
#include <vector>
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

class NumArray {
public:

    vector<int> acc;

    NumArray(vector<int> nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            acc.push_back(sum);
        }
        printVector(acc);
    }
    
    //98.26%    36ms
    //66.05%    17.2MB
    int sumRange(int i, int j) {
        int prevSum;
        if (i == 0) {
            prevSum = 0;
        }
        else {
            prevSum = acc[i-1];
        }
        return acc[j] - prevSum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main(int argc, char ** argv) {

    int nums[] = {-2, 0, 3, -5, 2, -1};
    vector<int> v(nums, nums + sizeof(nums) / sizeof(int));

    NumArray arr(v);
    cout << arr.sumRange(0, 2) << endl;
    cout << arr.sumRange(2, 5) << endl;
    cout << arr.sumRange(0, 5) << endl;
    cout << arr.sumRange(1, 2) << endl;

    return 0;
}