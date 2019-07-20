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
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        vector<int> dp(A.size(), 0);

        int d = 1;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                dp[i] = dp[i-1] + d;
                d++;
            }
            else {
                dp[i] = dp[i-1];
                d = 1;
            }
        }

        return dp[A.size() - 1];
    }
};

int main(int argc, char ** argv) {

    // vector<int> A = {1, 2, 3, 4, 5};
    // vector<int> A = {1, 2, 3, 4};
    vector<int> A = {1, 2, 3, 4, 5, 7, 1, 2, 3};
    cout << Solution().numberOfArithmeticSlices(A) << endl;

    return 0;
}