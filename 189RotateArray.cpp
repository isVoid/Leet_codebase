#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include "dbg.hpp"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // Extra Array
    // 20ms 100%
    // 9,7MB
    // void rotate(vector<int>& nums, int k) {

    //     k = k % nums.size();
    //     vector<int> t(nums.end()-k, nums.end());
    //     nums.erase(nums.end()-k, nums.end());
    //     nums.insert(nums.begin(), t.begin(), t.end());
    // }

    // Cyclic Swap
    //20ms 100%
    //9.6MB
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int cnt = 0;
        for (int i = 0; cnt < nums.size(); i++) {
            int t = nums[i];
            int j = i;
            do
            {
                int tp = (j+k) % nums.size();
                int tt = nums[tp];
                nums[tp] = t;
                t = tt;
                j = (j + k) % nums.size();
                cnt++;

            } while (j != i);

        }
    }
};

int main() {

    int k = 2;
    // int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // int arr[] = {3, 99, -1, 100};
    int arr[] = {1};
    vector<int> v = vectorFromArray(arr, sizeof(arr));

    Solution s;
    s.rotate(v, k);

    printVector(v);

    return 0;
}