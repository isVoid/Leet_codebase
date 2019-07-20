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
    //8ms 91.56%
    //10.3MB 49.44%
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        
        int a = 0, b = nums.size()-1;
        int begin, end;
        while (a <= b) {
            int c = (a + b) / 2;
            if (nums[c] >= target) {
                b = c - 1;
            }
            else {
                a = c + 1;
            }
        }
        a = a == nums.size() ? a-1 : a;
        b = b == -1 ? b+1 : b;

        // cout << a << " " << b << endl;
        if (nums[a] == target) {
            begin = a;
        }
        else if (nums[b] == target) {
            begin = b;
        }
        else {
            return {-1, -1};
        }

        a = 0, b = nums.size()-1;
        while (a <= b) {
            int c = (a + b) / 2;
            if (nums[c] > target) {
                b = c - 1;
            }
            else {
                a = c + 1;
            }
        }
        a = a == nums.size() ? a-1 : a;
        b = b == -1 ? b+1 : b;

        if (nums[a] == target) {
            end = a;
        }
        else if (nums[b] == target) {
            end = b;
        }

        return {begin, end};
        
    }
};

int main(int argc, char ** argv) {
    int target = 5;
    // vector<int> arr = {5, 7, 7, 8, 8, 10};
    // vector<int> arr = {5, 7, 7, 8, 8, 8, 9, 9, 9, 9, 9, 10, 11, 15, 18, 20};
    // vector<int> arr = {5, 7, 7, 8, 8, 8, 9, 9, 9, 9, 9, 10, 11, 15, 18, 20, 31};
    // vector<int> arr = {5, 7, 7, 8, 8, 8, 9, 9, 9, 9, 9, 10, 11, 15, 18, 20, 31};
    vector<int> arr = {};

    printVector(Solution().searchRange(arr, target));

    return 0;
}