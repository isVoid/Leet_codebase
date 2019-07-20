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
    //12ms 83.29%
    //9.9MB 60.88%
    int findDuplicate(vector<int>& nums) {
        int tortoise = 0;
        int hare = 0;

        do {
            tortoise = nums[tortoise];
            hare = nums[hare];
            hare = nums[hare];
        } while (tortoise != hare);


        tortoise = 0;
        while (nums[tortoise] != nums[hare]) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return nums[tortoise];
    }
};

int main(int argc, char ** argv) {

    vector<int> v = {1, 4, 6, 6, 6, 2, 3};

    cout << Solution().findDuplicate(v) << endl;

    return 0;
}