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

    // struct nE {
    //     int n;
    //     char e;
    // };
    //20ms 66.06%
    //14.3MB 9.64%
    // vector< vector<int> > merge(vector<vector<int>>& intervals) {
    //     vector< vector<int> > ans;
    //     vector<int> lower;
    //     vector<int> higher;
    //     vector<nE> nEs;
    //     for (auto it : intervals) {
    //         lower.push_back(it[0]);
    //         higher.push_back(it[1]);
    //     }

    //     sort(lower.begin(), lower.end());
    //     sort(higher.begin(), higher.end());

    //     int i = 0, j = 0;
    //     while (i < lower.size() || j < higher.size()) {
    //         if (i < lower.size() && j < higher.size()) {
    //             if (lower[i] <= higher[j]) {
    //                 nEs.push_back({lower[i], '('});
    //                 i++;
    //             }
    //             else {
    //                 nEs.push_back({higher[j], ')'});
    //                 j++;
    //             }
    //         }
    //         else if (i == lower.size()) {
    //             nEs.push_back({higher[j], ')'});
    //             j++;
    //         }
    //     }

    //     // printVector(lower);
    //     // printVector(higher);

    //     stack<nE> s;
    //     for (auto elem : nEs) {
    //         if (elem.e == '(') {
    //             s.push(elem);
    //         }
    //         else {
    //             nE first_elem = s.top();
    //             s.pop();
    //             if (s.empty()) {
    //                 ans.push_back({first_elem.n, elem.n});
    //             }
    //         }
    //     }

    //     return ans;
    // }

    //16ms 81.71%
    //13.4MB 10.79%
    vector< vector<int> > merge(vector<vector<int>>& intervals) {
        vector< vector<int> > ans;
        vector<int> lower;
        vector<int> higher;
        for (auto it : intervals) {
            lower.push_back(it[0]);
            higher.push_back(it[1]);
        }

        sort(lower.begin(), lower.end());
        sort(higher.begin(), higher.end());

        stack<int> s;
        int i = 0, j = 0;
        while (i < lower.size() || j < higher.size()) {
            if (i < lower.size() && lower[i] <= higher[j]) {
                s.push(lower[i]);
                i++;
            }
            else {
                int t = s.top();
                s.pop();
                if (s.empty()) {
                    ans.push_back({t, higher[j]});
                }
                j++;
            }
        }

        return ans;
    }
};

int main(int argc, char ** argv) {

    vector< vector<int> > itvl = {{1,3},{2,6},{8,10},{15,18}};
    // vector< vector<int> > itvl = {{1,4},{2,5}};

    printMatrix(Solution().merge(itvl));

    return 0;
}