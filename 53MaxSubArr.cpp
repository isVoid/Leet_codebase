#include <iostream>
#include <vector>
using namespace std;

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

class Solution {
public:
    // 208ms, O(n^2)
    int maxSubArray(vector<int>& nums) {
        int curMax = INT_MIN;
        int curI, curJ;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            // pointer for subarr
            int j = i;
            for (; j < nums.size(); j++) {
                sum += nums[j];
                if (sum > curMax) {
                    curMax = sum;
                    curI = i;
                    curJ = j;
                 }
            }
        }
        cout << curI << " " << curJ << endl;
        return curMax;
    }
};

int main() {

    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);

    Solution s;
    cout << s.maxSubArray(nums) << endl;

    return 0;
}