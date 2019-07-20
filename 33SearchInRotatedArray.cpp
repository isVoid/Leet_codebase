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
    //4ms 88.59%
    //8.7MB 78.53%
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        //Locate the turning point
        int a = 0, b = nums.size() - 1, c = b;
        
        while (c > 1) {
            if (a + c < nums.size() && nums[a] <= nums[a + c]) {
                a = a + c;
            }
            else {
                c = ceil(c / 2.);
            }
        }
        if (a < nums.size() - 1 && nums[a] <= nums[a+1]) {
            a = a + 1;
        }

        if (a == nums.size()-1) {
            a = 0;
            b = nums.size()-1;
        }
        else if (nums[0] <= target && nums[a] >= target) {
            b = a;
            a = 0;
        }
        else if (nums[a+1] <= target && nums[nums.size()-1] >= target) {
            a = a + 1;
            b = nums.size()-1;
        }
        else {
            return -1;
        }

        // cout << a << " " << b << endl;

        //Find target
        while (a < b) {
            int c = (a + b) / 2;
            if (nums[c] < target) {
                a = c + 1;
            }
            else if (nums[c] > target) {
                b = c - 1;
            }
            else {
                return c;
            }
        }

        if (a >= 0 && a < nums.size() && nums[a] == target) return a;
        else if (b >= 0 && b < nums.size() && nums[b] == target) return b;
        else return -1;
    }
};
int main(int argc, char ** argv) {

    // vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    // vector<int> v = {4, 5, 6, 7, 0, 1, 2, 3};
    // vector<int> v = {100, 101, 102, 0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    // vector<int> v = {99, 100, 101, 102, 0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    // vector<int> v = {100, 101, 102, 0};
    // vector<int> v = {0, 1, 2};
    // vector<int> v = {1};
    vector<int> v = {1, 3, 5};
    // vector<int> v = {1, 3};
    // vector<int> v = {};

    cout << Solution().search(v, 0) << endl;

    return 0;
}