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
    //52ms 98.95%
    //10MB 27.93%
     vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        if (num > 0) ans.push_back(1);
        else return ans;

        int t = 1;
        int j = 1;
        int flag = 0;
        for (int i = 2; i <= num; i++) {
            if (flag == 0) {
                ans.push_back(ans[i-t]);
                j++;
                if (j > t) {
                    flag = 1;
                    j = 1;
                }
            }
            else {
                ans.push_back(ans[i-t]+1);
                j++;
                if (j > t) {
                    flag = 0;
                    j = 1;
                    t *= 2;
                }
            }
        }

        return ans;
    }
};

int main(int argc, char ** argv) {

    int n = 1;

    vector<int> ans = Solution().countBits(n);

    printVector(ans);

    return 0;
}