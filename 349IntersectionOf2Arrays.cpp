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
    //8ms 88.07%
    //9MB 86.10%
    //Taking prev value away solves 350IntersectionOf2ArraysII
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;
        int prev = -1;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                if (nums1[i] != prev) {
                    ans.push_back(nums1[i]);
                    prev = nums1[i];
                }
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                j++;
            }

        }
        return ans;
    }
};
int main(int argc, char ** argv) {

    // vector<int> v1 = {1, 2, 2, 1};
    // vector<int> v2 = {2, 2};

    vector<int> v1 = {4,9,5};
    vector<int> v2 = {9,4,9,8,4};

    printVector(Solution().intersection(v1, v2));

    return 0;
}