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

    vector< vector<int> > threeSum(vector<int>& n) {
        vector< vector<int> > r;
        sort(n.begin(), n.end());

        for (int i = 0; i < n.size(); i++) {
            int target = -n[i];
            int front = i + 1, back = n.size() - 1;

            while (front < back) {
                
                int sum = n[front] + n[back];
                if (sum < target) {
                    front++;
                }

                else if (sum > target) {
                    back--;
                }

                else {
                    vector<int> v;
                    v.push_back(n[i]);
                    v.push_back(n[front]);
                    v.push_back(n[back]);

                    r.push_back(v);

                    while (front < back && n[front] == v[1]) front++;
                    while (front < back && n[back] == v[2]) back--;
                }
            }

            while (i + 1 < n.size() && n[i + 1] == n[i]) i++;
        }
        return r;
    }
};

int main(int argc, char ** argv) {

    // int a[] = {-1,0,1,2,-1,-4};
    // int a[] = {1, 1, -2};
    // int a[] = {0, 0, 0};
    // int a[] = {0, 0};
    // int a[] = {-1,0,1,0};
    // int a[] = {-1, 0, 1, 2, -1, -1, -4};
    // int a[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    int a[] = {2,-8,8,6,-14,-12,11,-10,13,14,7,3,10,-13,3,-15,7,3,-11,-8,4,5,9,11,7,1,3,13,14,-13,3,-6,-6,-12,-15,-12,-9,3,-15,-11,-6,-1,0,11,2,-12,3,-6,6,0,-6,-12,-10,-12,6,5,-4,-5,-5,-4,-11,13,5,-2,-13,-3,-7,-15,8,-15,12,-13,0,-3,6,9,-8,-6,10,5,9,-11,0,7,-15,-8,-3,-4,-6,7,7,-2,-2,-11,3,0,-6,12,0,-13,4,-3,11,-11,1,2,13,8,4,9,-1,-2,5,14,12,5,13,-6,-13,-8,9,1,5,-8,-2,-6,-1};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    vector< vector<int> > r = Solution().threeSum(v);
    for (auto rv : r) {
        printVector(rv);
    }

    return 0;
}