#include <iostream>
#include <vector>
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

    //20ms 98.41%
    //9.7MB 99.58%
    int maxArea(vector<int>& h) {
        int maxA = 0;
        int l = 0, r = h.size()-1;

        while (r > l) {
            int A = (r - l) * min(h[r], h[l]);

            if (A > maxA) {
                maxA = A;
            }

            if (h[r] >= h[l]) {
                l++;
            }
            else {
                r--;
            }
        }

        return maxA;
    }

    //180ms 27.56%
    //9.7MB 99.72%
    // int maxArea(vector<int>& h) {
    //     int maxA = 0;
    //     for (int i = 0; i < h.size(); i++) {
    //         int j = ceil(float(maxA) / h[i]) + i;
    //         for (; j < h.size(); j++) {
    //             int A = abs(i-j) * min(h[i], h[j]);
    //             if (A > maxA) {
    //                 maxA = A;
    //             }
    //         }
    //     }
    //     return maxA;
    // }
};

int main(int argc, char ** argv) {

    int a[] = {1,8,6,2,5,4,8,3,7};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    cout << Solution().maxArea(v) << endl;

    return 0;
}