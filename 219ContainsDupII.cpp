#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include "dbg.hpp"
using namespace std;

struct ListNode;
class Solution {
public:
    //32ms 95.45%
    //With <map> 48ms
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> maxIndices;
        for (int i = 0; i < nums.size(); i++) {
            if (maxIndices.find(nums[i]) != maxIndices.end()) {
                if (i - maxIndices[nums[i]] <= k) {
                    printf("Pair <%d, %d> diff leq than %d\n", i, maxIndices[nums[i]], k);
                    return true;
                }
                    
            }
            maxIndices[nums[i]] = i;
        }
        return false;
    }
};

int main(int argc, char ** argv) {

    // int n[] = {1, 2, 3, 1};
    // int n[] = {1, 0, 1, 1};
    int n[] = {1,2,3,1,2,3};
    vector<int> nums(n, n + sizeof(n)/sizeof(int));
    int k = 2;
    Solution s;

    cout << s.containsNearbyDuplicate(nums, k) << endl;

    return 0;
}