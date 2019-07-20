#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
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

    // // Runtime: 208 ms, faster than 48.83%
    // // Memory Usage: 24.8 MB, less than 33.39%
    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     //pre-process
    //     map< string, vector<int> > adj;
    //     for (int i = 0; i < wordList.size(); i++) {
    //         for (int j = 0; j < wordList[i].length(); j++) {
    //             char c = wordList[i][j];
    //             wordList[i][j] = '*';
    //             if (adj.count(wordList[i]) == 0) {
    //                 adj[wordList[i]] = vector<int>();
    //                 adj[wordList[i]].emplace_back(i);
    //             }
    //             else {
    //                 adj[wordList[i]].emplace_back(i);
    //             }
    //             wordList[i][j] = c;
    //         }
    //     }

    //     for (map< string, vector<int> >::iterator it = adj.begin();
    //             it != adj.end(); it++) {
    //         cout << (*it).first << " -> ";
    //         printVector((*it).second);
    //     }

    //     //BFS
    //     queue< pair<int, int> > bfs;
    //     set<int> visited;
    //     for (int i = 0; i < beginWord.length(); i++) {
    //         char c = beginWord[i];
    //         beginWord[i] = '*';
    //         if (adj.count(beginWord) != 0) {
    //             for (int idx : adj[beginWord]) {
    //                 bfs.emplace(make_pair(idx, 1));
    //                 visited.emplace(idx);
    //             }
    //         }
    //         beginWord[i] = c;
    //     }

    //     int level = 1;
    //     while (!bfs.empty()) {
    //         printQueue(bfs);
    //         int idx = bfs.front().first;
    //         string next = wordList[idx];
    //         level = bfs.front().second;
    //         bfs.pop();

    //         if (next == endWord) {
    //             return 1+level;
    //         }

    //         for (char &c : next) {
    //             char tmp = c;
    //             c = '*';
    //             if (adj.count(next) != 0) {
    //                 for (int idx : adj[next]) {
    //                     if (visited.find(idx) == visited.end()) {
    //                         bfs.emplace(make_pair(idx, level+1));
    //                         visited.emplace(idx);
    //                     }
    //                 }
    //             }
    //             c = tmp;
    //         }
    //     }

    //     return 0;
    // }

    // // 148 ms	14.6 MB
    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
    //     unordered_set<string> dict(wordList.begin(), wordList.end());
    //     unordered_set<string> visited;

    //     queue<pair<string, int> > bfs;
    //     int level = 0;
    //     bfs.push({beginWord, level});
    //     visited.insert(beginWord);
    //     while (!bfs.empty()) {
    //         string cur = bfs.front().first;
    //         level = bfs.front().second;
    //         bfs.pop();

    //         if (cur == endWord) {
    //             return 1+level;
    //         }

    //         //get neightbor
    //         for (char &c : cur) {
    //             char tmp = c;
    //             for (int i = 0; i < 26; i++) {
    //                 c = 'a' + i;
    //                 if (dict.find(cur) != dict.end() && visited.find(cur) == visited.end()) {
    //                     bfs.push({cur, level+1});
    //                     visited.emplace(cur);
    //                 }
    //             }
    //             c = tmp;
    //         }
    //     }

    //     return 0;
    // }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict(wordList.begin(), wordList.end());

        queue<pair<string, int> > bfs;
        int level = 0;
        bfs.push({beginWord, level});
        while (!bfs.empty()) {
            string cur = bfs.front().first;
            level = bfs.front().second;
            bfs.pop();

            if (cur == endWord) {
                return 1+level;
            }

            //get neightbor
            for (char &c : cur) {
                char tmp = c;
                for (int i = 0; i < 26; i++) {
                    c = 'a' + i;
                    if (dict.find(cur) != dict.end()) {
                        bfs.push({cur, level+1});
                        dict.erase(cur);
                    }
                }
                c = tmp;
            }
        }

        return 0;
    }
};

int main(int argc, char ** argv) {

    string begin = "hit", end = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << Solution().ladderLength(begin, end, wordList) << endl;

    return 0;
}