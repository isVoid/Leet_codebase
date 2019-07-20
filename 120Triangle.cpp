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
    //8ms 98.99%
    //10.3MB 13.41%
    int minimumTotal(vector< vector<int> >& triangle) {
        if (triangle.size() == 0) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        if (triangle.size() == 2) return triangle[0][0] + min(triangle[1][0], triangle[1][1]);

        vector< vector<int> > vv; 
        vector<int> v1 = {triangle[0][0]};
        vector<int> v2 = {triangle[1][0] + triangle[0][0] , triangle[1][1] + triangle[0][0]};

        vv.push_back(v1);
        vv.push_back(v2);

        for (int i = 2; i < triangle.size(); i++) {
            cout << "here" << i << endl;
            vector<int> v;
            int minStep;

            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    minStep = vv[i-1][0] + triangle[i][j];
                }
                else if (j == triangle[i].size()-1) {
                    minStep = vv[i-1][triangle[i-1].size()-1] + triangle[i][j];
                }
                else {
                    minStep = min(vv[i-1][j-1], vv[i-1][j]) + triangle[i][j];
                }
                v.push_back(minStep);
            }
            vv.push_back(v);
        }

        //debug
        for (int i = 0; i < vv.size(); i++) {
            printVector(vv[i]);
        }

        int ans = INT_MAX;
        vector<vector<int> >::iterator le = vv.end()-1;
        for (int i = 0; i < (*le).size(); i++) {
            if ((*le)[i] < ans) ans = (*le)[i];
        }

        return ans;
    }
};

int main(int argc, char ** argv) {

    vector<int> v1 = {2};
    vector<int> v2 = {3, 4};
    vector<int> v3 = {6, 5, 7};
    vector<int> v4 = {4, 1, 8, 3};

    vector< vector<int> > vv = {v1, v2, v3, v4};

    cout << Solution().minimumTotal(vv) << endl;

    return 0;
}