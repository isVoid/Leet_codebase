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
    // Runtime: 4 ms, faster than 99.41%
    // Memory Usage: 9 MB, less than 67.89%
    //https://leetcode.com/problems/gas-station/discuss/42572/Proof-of-%22if-total-gas-is-greater-than-total-cost-there-is-a-solution%22.-C%2B%2B
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = -1, sum = 0, minParSum = INT_MAX;
        for (int i = 0; i < gas.size(); i++) {
            sum += (gas[i] - cost[i]);
            if (sum < minParSum) {
                start = i;
                minParSum = sum;
            }
        }
        return sum >= 0 ? (1+start)%gas.size() : -1;
    }
};

int main(int argc, char ** argv) {

    vector<int> gas  = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << Solution().canCompleteCircuit(gas, cost) << endl;


    return 0;
}