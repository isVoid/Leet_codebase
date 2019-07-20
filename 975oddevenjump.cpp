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
    int oddEvenJumps(vector<int>& A) {
        //dp[i]=true, good start from i as odd step
        vector<bool> dp(A.size(), false);
        //dp2[i]=true, good start from i as even step
        vector<bool> dp2(A.size(), false);
        int cnt = 1;

        dp[A.size()-1] = true;
        dp2[A.size()-1] = true;

        for (int i = dp.size()-2; i >= 0; i--) {
            int j = i+1, k = i+1;
            
        }

        printVector(dp);

        return cnt;
    }
};

int main(int argc, char ** argv) {

    vector<int> v = {10, 13, 12, 14, 15};
    cout << Solution().oddEvenJumps(v) << endl;

    return 0;
}