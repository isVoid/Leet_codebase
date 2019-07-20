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

    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> pos;    //{num, pos}
    //     vector<int> n, freq;

    //     for (int i = 0; i < nums.size(); i++) {
    //         cout << nums[i] << endl;
    //         if (pos.find(nums[i]) == pos.end()) {
    //             pos.insert({nums[i], n.size()});
    //             n.emplace_back(nums[i]);
    //             freq.emplace_back(1);
    //         }
    //         else {
    //             int p = pos[nums[i]];
    //             freq[p]++;
    //             int q = p;
    //             while (q >= 1 && freq[q-1] < freq[p]) {
    //                 q--;
    //             }
    //             pos[n[p]] = q;
    //             pos[n[q]] = p;
    //             swap(freq[q], freq[p]);
    //             swap(n[q], n[p]);
    //         }
    //     }

    //     n.resize(k);
    //     return n;
    // }

    // Runtime: 20 ms, faster than 84.26% 
    // Memory Usage: 11.2 MB, less than 96.62% 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> cnt;
        for (int n : nums) {
            if (cnt.find(n) == cnt.end()) {
                cnt.insert({n, 1});
            }
            else {
                cnt[n]++;
            }
        }

        priority_queue< pair<int, int> > pq;
        for (auto item : cnt) {
            pq.push({item.second, item.first});
        }

        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.emplace_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};

int main(int argc, char ** argv) {

    // vector<int> v = {1, 1, 1, 2, 2, 3};
    vector<int> v = {1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4};
    // vector<int> v = {1, 1, 1};
    printVector(Solution().topKFrequent(v, 2));

    return 0;
}