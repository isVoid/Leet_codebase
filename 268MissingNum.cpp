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

    //24ms 98.06%
    //9.6MB 98.36%
    int missingNumber(vector<int> &nums) {
        int sum = 0;
        for (auto &n : nums) {
            sum += n;
        }
        int sum2 = (0 + nums.size()) * (nums.size() + 1) / 2;

        return sum2 - sum;
    }
};

int main(int argc, char ** argv) {

    // int arr[] = {3, 0, 1};
    // int arr[] = {9,6,4,2,3,5,7,0,1};
    int arr[] = {0};
    // int arr[] = {0, 1};
    // int arr[] = {1};
    // int arr[] = {1, 0};
    // int arr[] = {2, 0};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

    Solution s;
    cout << s.missingNumber(v) << endl;

    return 0;
}