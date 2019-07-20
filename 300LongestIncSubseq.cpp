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
    //64ms 7.82%
    //8.8MB 17.01%
    // int lengthOfLIS(vector<int>& nums) {
    //     if (nums.size() == 0) return 0;
    //     if (nums.size() == 1) return 1;

    //     vector<int> lis;
    //     for (int i = 0; i < nums.size(); i++) 
    //         lis.push_back(0);
    //     lis[lis.size()-1] = 1;  //base
    //     int ans = INT_MIN;

    //     for (int i = lis.size()-2; i >= 0; i--) {
    //         lis[i] = 1;
    //         for (int j = i+1; j < lis.size(); j++) {
    //             if (nums[i] < nums[j]) {
    //                 lis[i] = max(lis[j] + 1, lis[i]);
    //             }
    //         }
    //         ans = max(ans, lis[i]);
    //     }
    //     printVector(nums, "\t");
    //     printVector(lis, "\t");
    //     return ans;
    // }

    int bs(vector<int>& v, int t) {
        int a = 0, b = v.size();

        while (a < b) {
            int c = (a+b)/2;
            if (t < v[c]) b = c-1;
            else if (t > v[c]) a = c+1;
            else return c;
        }

        // cout << a << " " << b << endl;
        if (b == a)  return b;
        else return b+1;

    }

    //0ms 100.0%
    //8.8MB 11.73%
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        vector<int> curlis;
        curlis.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            int pos = bs(curlis, nums[i]);
            // cout << i << " " << pos << " " << curlis.size() << endl;
            if (pos == curlis.size())
                curlis.push_back(nums[i]);
            else if (pos+1 < curlis.size() && curlis[pos] < nums[i]) {
                curlis[pos+1] = nums[i];
            }
            else {
                curlis[pos] = nums[i];
            }
            // printVector(curlis);
        }

        return curlis.size();
    }

};

int main(int argc, char ** argv) {

    // vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    // vector<int> v;
    // vector<int> v = {1};
    // vector<int> v = {1, 2};
    // vector<int> v = {2, 1};
    // vector<int> v = {1, 2, 3, 4};
    // vector<int> v = {4, 3, 2, 1};
    // vector<int> v = {10,9,2,5,3,4};

    cout << Solution().lengthOfLIS(v) << endl;

    //test bs
    // vector<int> v = {2, 4, 6, 8, 10};

    // cout << Solution().bs(v, 0) << endl;

    return 0;
}