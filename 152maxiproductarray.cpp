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

    //8ms 68.07%
    //9MB 73.02%
    int maxProduct(vector<int>& nums) {
        int max_i[2];
        int min_i[2];
        max_i[0] = nums[0];
        min_i[0] = nums[0];
        max_i[1] = 0;
        min_i[1] = 0;
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            max_i[i%2] = max(max_i[(i-1)%2] * nums[i], max(min_i[(i-1)%2] * nums[i], nums[i]));
            min_i[i%2] = min(min_i[(i-1)%2] * nums[i], min(max_i[(i-1)%2] * nums[i], nums[i]));
            ans = max(ans, max_i[i%2]);
            // cout << max_i[i%2] << " " << min_i[i%2] << endl;
        }

        return ans;
    }
};

int main(int argc, char ** argv) {

    // vector<int> n = {2, 3, -1, 4, 2, -3};
    // vector<int> n = {6, -3, -10, 0, 2};
    // vector<int> n = {-1, -3, -10, 0, 60};
    // vector<int> n = {-2, -3, 0, -2, -40};
    // vector<int> n = {2, 3, -2, 4};
    // vector<int> n = {-2, 0, -1};
    // vector<int> n = {-1, -1};
    vector<int> n = {2,-5,-2,-4,3};

    cout << Solution().maxProduct(n) << endl;

    return 0;
}