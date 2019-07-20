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
    int n, med;
    void wiggleSort(vector<int>& nums) {
        n = nums.size() - 1;
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        med = nums[n/2];
        
        int i = 0, j = 0, p = n;

        while (j <= p) {
            int _i = __m(i), _j = __m(j), _p = __m(p);
            if (nums[_j] < med) {
                swap(nums[_i], nums[_j]);
                i++;
                j++;
            }
            else if (nums[_j] > med) {
                swap(nums[_j], nums[_p]);
                p--;
            }
            else {
                j++;
            }
        }

    }

    inline int __m(int i) {
        int mid = n / 2;
        if (i <= mid) return (mid - i) * 2;
        else return 1 + 2 * (n - i);
    }
};

int main(int argc, char ** argv) {

    vector<int> nums = {18 ,17 ,19 ,16  ,15  ,11 ,14 ,10 ,13 ,12};

    Solution().wiggleSort(nums);

    printVector(nums);

    return 0;
}