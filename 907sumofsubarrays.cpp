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
    int sumSubarrayMins(vector<int>& A) {
        stack<int> stk, stk2;
        vector<int> left(A.size(), -1), right(A.size(), -1);
        int MOD = 1e9 + 7;

        for (int i = 0; i < A.size(); i++) {
            while (!stk.empty() && stk.top() > A[i]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        for (int i = 0; i < A.size(); i++) {
            while (!stk2.empty() && stk2.top() > A[i]) {
                int x = stk2.top();
                stk2.pop();
                right[x] = i;
            }
            stk2.push(i);
        }

        printVector(A);
        printVector(left);
        printVector(right);

        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            if (left[i] == -1) {
                ans += A[i] * (right[i] - i);
            }
            else if (right[i] == -1) {
                ans += A[i] * (i - left[i]);
            }
            else if (left[i] == -1 && right[i] == -1) {
                ans = ans;
            }
            else {
                ans += A[i] * (i - left[i]) * (right[i] - i);
            }
        }

        return ans % MOD;
    }
};

int main(int argc, char ** argv) {

    vector<int> v = {3, 1, 2, 4};

    cout << Solution().sumSubarrayMins(v) << endl;

    return 0;
}