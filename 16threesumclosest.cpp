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
#include <climits>
#include "dbg.hpp"
using namespace std;

struct ListNode;
struct TreeNode;
class Solution {
public:
    //8ms 100%
    //8.7MB 99.72%
    int threeSumClosest(vector<int>& n, int target) {
        int minDSum = 0;
        int minD = INT_MAX;
        sort(n.begin(), n.end());

        for (int i = 0; i < n.size(); i++) {
            // cout << i << " " << n[i] << endl;
            int f = i+1, b = n.size() - 1;

            while (f < b) {
                int sum = n[i] + n[f] + n[b];
                int d = abs(sum - target);

                if (d < minD) {
                    cout << i << " " << n[i] << " " << n[f] << " " << n[b] << endl;
                    cout << d << " " << sum << " " << minD << " " << minDSum << endl;
                    minD = d;
                    minDSum = sum;

                    // while (f + 1 < b && n[f] == n[f+1]) f++;
                    // while (f < b - 1 && n[b] == n[b-1]) b--;
                }
                
                if (sum < target) {
                    f++;
                }

                else if (sum > target) {
                    b--;
                }

                else {
                    return minDSum;
                }


            }

            while (i + 1 < n.size() && n[i] == n[i+1]) i++;
        }

        return minDSum;
    }
};

int main(int argc, char ** argv) {

    // vector<int> v({-1, 2, 1, -4});
    // vector<int> v({0, 1, 2});
    vector<int> v({-20, -19, -19,-18, -17});
    // vector<int> v({13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6});

    cout << Solution().threeSumClosest(v, -59) << endl;

    return 0;
}