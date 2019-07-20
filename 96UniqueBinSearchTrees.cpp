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
    //4ms 100%
    //8.3MB 36.77%
    int numTrees(int n) {
        vector<int> trees;
        trees.push_back(1);

        for (int i = 1; i <= n; i++) {
            trees.push_back(0);
            int p = 0;
            int q = i - 1;
            while (q >= 0) {
                // cout << p << " " << q << " " << trees[i] << endl;
                trees[i] += trees[p] * trees[q];
                p++;
                q--;
            }
        }

        return trees[n];
    }
};

int main(int argc, char ** argv) {

    cout << Solution().numTrees(4) << endl;

    return 0;
}