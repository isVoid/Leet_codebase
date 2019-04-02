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
class Solution {
public:
    //20ms 35.37%
    //9.5MB 74.75%
    // void moveZeroes(vector<int>& nums) {
    //     int z = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] == 0) {
    //             nums.erase(nums.begin() + i);
    //             z++;
    //             i--;
    //         }
    //     }
    //     for(int i = 0; i < z; i++)
    //     {
    //         nums.push_back(0);
    //     }
    // }

    // 16ms 99.46%
    // 9.4MB 100%
    void moveZeroes(vector<int>& nums) {
        int s = 0, f = 0;
        for (; f < nums.size(); f++) {
            if (nums[f] != 0) {
                swap(nums[s], nums[f]);
                s++;
            }
        }
    }
};

int main(int argc, char ** argv) {

    int n[] = {0, 0, 1, 0, 0};
    vector<int> v(n, n + sizeof(n) / sizeof(n[0]));

    Solution().moveZeroes(v);
    printVector(v);

    return 0;
}