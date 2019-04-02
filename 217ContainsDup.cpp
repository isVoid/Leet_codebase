#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include "dbg.hpp"
using namespace std;

struct ListNode;
class Solution {
public:
    //27.99% 60ms
    //13.75% 
    // bool containsDuplicate(vector<int>& nums) {
    //     set<int> rec;
    //     for (auto i : nums) {
    //         if (rec.find(i) != rec.end())
    //             return true;
    //         rec.insert(i);
    //     }
    //     return false;
    // }

    //sort
    //32ms, 80.91%
    //11.5MB, 69%
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) return false;

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};

int main(int argc, char ** argv) {

    // int arr[] = {1, 2 ,1, 8, 9};
    int arr[] = {2};
    // int arr[] = {};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(int));

    Solution s;
    cout << s.containsDuplicate(v) << endl;;

    return 0;
}