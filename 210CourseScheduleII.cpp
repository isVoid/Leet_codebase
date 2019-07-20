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

    // https://leetcode.com/articles/course-schedule-ii/
    // Runtime: 28 ms, faster than 55.31%
    // Memory Usage: 15.1 MB, less than 21.68%
    // DFS
    // vector<int> findOrder(int n, vector<vector<int>>& list) {
    //     vector< vector<int> > adjList(n, vector<int>());
    //     for (auto pair : list) {
    //         adjList[pair[1]].emplace_back(pair[0]);
    //     }

    //     vector<int> visited(n, 0); //0 unvisited, 1 visiting, 2 visited;
    //     vector<int> path;

    //     for (int start = 0; start < n; start++) {
    //         if (!dfs(adjList, visited, path, start)) {
    //             return vector<int>();
    //         }
    //     }

    //     reverse(path.begin(), path.end());
    //     return path;

    // }

    // bool dfs(vector< vector<int> > &adjList, vector<int> &visited, vector<int> &path, int i) {
    //     if (visited[i] == 1) return false;
    //     if (visited[i] == 2) return true;

    //     visited[i] = 1;
    //     for (int neighbor : adjList[i]) {
    //         if (!dfs(adjList, visited, path, neighbor)) {
    //             return false;
    //         }
    //     }
    //     path.push_back(i);
    //     visited[i] = 2;

    //     return true;
    // }


    //In-degree Method
    vector<int> findOrder(int n, vector<vector<int>>& list) {
        vector< vector<int> > adjList(n, vector<int>());
        vector<int> inDegree(n, 0);
        for (auto pair : list) {
            adjList[pair[1]].emplace_back(pair[0]);
            inDegree[pair[0]]++;
        }

        queue<int> tSort;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                tSort.push(i);
            }
        }

        vector<int> path;

        while (!tSort.empty()) {
            int cur = tSort.front();
            tSort.pop();
            path.push_back(cur);

            for (int neighbor : adjList[cur]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    tSort.push(neighbor);
                }
            }
        }

        return path.size() == n ? path : vector<int>();
    }

};

int main(int argc, char ** argv) {

    // vector< vector<int> > pre = {{1, 0}, {0, 1}};
    // int n = 2;

    // vector< vector<int> > pre = {{1,0},{2,0},{3,1},{3,2}};
    // int n = 4;

    // int n = 7;
    // vector< vector<int> > pre = {{1,0},{0,3},{0,2},{3,2},{2,5},{4,5},{5,6},{2,4}};

    int n = 3;
    vector< vector<int> > pre = {{1,0},{1,2},{0,1}};

    printVector(Solution().findOrder(n, pre));

    return 0;
}