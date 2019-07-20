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
#include <random>
#include "dbg.hpp"
using namespace std;

struct ListNode;
struct TreeNode;
class Solution {
public:

    //Partition Subroutine
    // Runtime: 52 ms, faster than 19.81%
    // Memory Usage: 9 MB, less than 99.66%
    //->
    //With Shuffle:
    //Runtime: 16 ms, faster than 52.24% 
    // Memory Usage: 9.3 MB, less than 60.08% 
    // int findKthLargest(vector<int>& nums, int k) {
        
    //     shuffle(nums.begin(), nums.end(), default_random_engine(0));
    //     int lo = 0, hi = nums.size()-1, kth;
    //     while (true) {

    //         int pIdx = partition(nums, lo, hi);
    //         if (pIdx == k-1) {
    //             kth = nums[pIdx];
    //             break;
    //         }
    //         else if (pIdx > k-1) {
    //             hi = pIdx - 1;
    //         }
    //         else {
    //             lo = pIdx + 1;
    //         }
    //     }

    //     return kth;

    // }

    // int partition(vector<int> &nums, int lo, int hi) {
    //     int pivot = nums[lo], l = lo+1, r = hi;

    //     while (l <= r) {
    //         if (nums[l] < pivot && nums[r] > pivot) {
    //             swap(nums[l], nums[r]);
    //             l++; r--;
    //         }
    //         else if (nums[l] >= pivot) {
    //             l++;
    //         }
    //         else if (nums[r] <= pivot) {
    //             r--;
    //         }
    //     }
    //     swap(nums[lo], nums[r]);
    //     return r;
    // }

    // Runtime: 12 ms, faster than 83.05%
    // Memory Usage: 9.2 MB, less than 77.94%
    // int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size() - k];
    // }

    //Priority Queue
    // Runtime: 16 ms, faster than 52.24%
    // Memory Usage: 9.7 MB, less than 19.42%
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;

        for (int n : nums) {
            q.push(n);
        }
        for (int i = 0; i < k-1; i++) {
            q.pop();
        }

        return q.top();
    }

};
int main(int argc, char ** argv) {

    vector<int> v = {3,2,1,5,6,4};
    int k = 2;

    cout << Solution().findKthLargest(v, k) << endl;

    return 0;
}