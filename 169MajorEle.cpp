#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include "dbg.hpp"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // //Hashmap
    // // 32ms 27.91%
    // // 11.3MB
    // int majorityElement(vector<int>& nums) {
    //     map<int, int> cnts;
    //     int mx = INT_MIN, mn = 0;
    //     for (auto i : nums) {
    //         if (cnts.find(i) == cnts.end()) {
    //             cnts[i] = 1;
    //         }
    //         else {
    //             cnts[i]++;
    //         }
    //         if (cnts[i] > mx) {
    //             mx = cnts[i];
    //             mn = i;
    //         }
    //     }

    //     return mn;
    // }

    // sort
    // 32ms, 27.91%
    // 11.2MB
    // int majorityElement(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size() / 2];
    // }


    //Boyer Moore
    //If the current number equals the candidate number
    //vote it, otherwise decrease it.
    //When vote equals zero, it means in the subarray
    //before it, the count of candidate equals
    //those which are not candidate. So equally the
    //previous subarray contributes 0 to the majority
    //number, therefore it should be "forgotten".
    //The candidate should be re-elected as the start of
    //the rest of the array.
    //20ms, 99.42%
    //11.3MB
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int vote = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate) vote++;
            else vote--;

            if (vote == 0) {
                candidate = nums[i+1];
            }
        }
        return candidate;
    }
};

int main() {

    // int n[] = {2, 2, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 3, 3};
    // int n[] = {2, 3, 2};
    int n[] = {2};
    vector<int> v(n, n+sizeof(n)/sizeof(int));

    Solution s;
    cout << s.majorityElement(v) << endl;

    return 0;
}