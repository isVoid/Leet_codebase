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

    // Runtime: 20 ms, faster than 89.03% 
    // Memory Usage: 14.5 MB, less than 29.83%
    bool canFinish(int n, vector< vector<int> >& list) {
        vector< vector<int> > adjList(n, vector<int>());
        for (auto pair : list) {
            adjList[pair[0]].emplace_back(pair[1]);
        }

        vector<int> visited(n, 0); //0 unvisited, 1 visiting, 2 visited
        for (int i = 0; i < n; i++) {
            fill(visited.begin(), visited.end(), 0);
            if (dfs(adjList, visited, i)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(vector< vector<int> > &adjList, vector<int> &visited, int i) {

        if (visited[i] == 2) return false;
        if (visited[i] == 1) return true;

        visited[i] = 1;
        for (int neighbor : adjList[i]) {

            if (dfs(adjList, visited, neighbor)) {
                return true;
            }
        }
        visited[i] = 2;

        return false;
    }
};

int main(int argc, char ** argv) {

    // vector< vector<int> > pred = {{1, 0}};
    // vector< vector<int> > pred = {{1, 0}, {0, 1}};
    // int n = 2;

    // vector< vector<int> > pred = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    // int n = 4;

    vector< vector<int> > pred = {{0, 1}, {0, 2}, {1, 2}};
    int n = 3;

    cout << Solution().canFinish(n, pred) << endl;


    return 0;
}