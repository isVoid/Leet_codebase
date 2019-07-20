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

    vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 , 
     31, 37, 41, 43, 47, 53, 59, 61, 67, 71 , 
     73, 79, 83, 89, 97, 101, 103
    };
    
    long M = 10e9 + 7;
    
    long h(string s) {
        long ans = 1;
        for (int i = 0; i < s.size(); i++) {
            ans = (ans * primes[s[i] - 'a']) % M;
        }
        return ans;
    }
    
    //99.99% 24ms
    //98.27% 16.4MB
    vector< vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map< long, int > h2b;
        vector< vector<string> > buckets;
        for (int i = 0; i < strs.size(); i++) {
            long hash_code_final = h(strs[i]);

            if (h2b.find(hash_code_final) == h2b.end()) {
                h2b.insert(make_pair(hash_code_final, buckets.size()));
                buckets.push_back({strs[i]});
                
            }
            else {
                buckets[h2b[hash_code_final]].push_back(strs[i]);
            }
        }

        return buckets;
    }
};

int main(int argc, char ** argv) {

    // vector<string> vs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> vs = {"tao","pit","cam","aid","pro","dog"};
    // vector<string> vs = {"","b"};

    printMatrix(Solution().groupAnagrams(vs));

    return 0;
}