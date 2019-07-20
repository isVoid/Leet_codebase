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
    //4ms 95.61%
    //8.5MB 15.23%
    int integerBreak(int n) {
        vector<int> maxprod = {0, 1};

        for (int i = 2; i <= n; i++) {
            int mp = INT_MIN;
            for (int j = 1; j <= i-1; j++) {
                // mp = max(mp, j*maxprod[i-j]);
                // mp = max(max(mp, j*maxprod[i-j]), j*(j-i));
                mp = max(max(max(mp, j*maxprod[i-j]), j*(i-j)), maxprod[j]*maxprod[i-j]);
            }
            maxprod.push_back(mp);
        }

        printVector(maxprod);

        return maxprod[n];
    }
};

int main(int argc, char ** argv) {

    int n = 58;

    cout << Solution().integerBreak(n) << endl;

    return 0;
}