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

bool comp(const map<string, int>::iterator a, const map<string, int>::iterator b) {
    if ((*a).second > (*b).second) return true;

    else if ((*a).second == (*b).second) {
        return (*a).first.compare((*b).first) < 0;
    }

    else return false;
}

class Solution {
public:

    //20ms 93.59%
    //11.1MB 100%
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        vector< map<string, int>::iterator > v;
        vector<string> ans;

        //Time O(N), Space O(N)
        for (int i = 0; i < words.size(); i++) {
            if (m.count(words[i]) != 0) {
                m[words[i]]++;
            }
            else {
                pair<map<string, int>::iterator, bool> p = m.insert(make_pair(words[i], 1));
                v.push_back(p.first);
            }
        }

        //Time O(NlogN), Space O(N)
        sort(v.begin(), v.end(), comp);

        for (int i = 0; i < k; i++) {
            ans.push_back((*v[i]).first);
        }

        return ans;

    }
};

int main(int argc, char ** argv) {

    // vector<string> v = {"i", "love", "doggy", "and", "doggy", "hates", "i"};
    // vector<string> v = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> v = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    printVector(v);

    vector<string> ans = Solution().topKFrequent(v, 4);
    printVector(ans);

    // string a = "abcd", b = "bcde";
    // cout << a.compare(b) << endl;

    return 0;
}