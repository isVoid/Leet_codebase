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
    //52ms 8.99%
    //10.9MB 74.85%
    // bool canConstruct(string ransomNote, string magazine) {
    //     sort(ransomNote.begin(), ransomNote.end());
    //     sort(magazine.begin(), magazine.end());

    //     int i = 0, j = 0;
    //     while (i < ransomNote.length() && j < magazine.length()) {
    //         if (ransomNote[i] == magazine[j]) {
    //             i++;
    //             j++;
    //         }
    //         else if (ransomNote[i] > magazine[j]) {
    //             while (j < magazine.length() && ransomNote[i] > magazine[j]) {
    //                 j++;
    //             }
    //         }
    //         else {
    //             break;
    //         }
    //     }

    //     return i == ransomNote.length();
    // }

    //24ms 94.26%
    //10.8MB 85.86%
    bool canConstruct(string ransomNote, string magazine) {
        // vector<int> dict(26, 0);
        int *dict = new int[26]();
        
        for (int i = 0; i < magazine.length(); i++) {
            dict[magazine[i]-'a']++;
        }
        
        for (int i = 0; i < ransomNote.length(); i++) {
            dict[ransomNote[i]-'a']--;
            if (dict[ransomNote[i]-'a'] < 0) return false;
        }

        return true;
    }
};

int main(int argc, char ** argv) {

    // string r = "aab", m = "aabbc";
    // string r = "aab", m = "aa";
    // string r = "aab", m = "bba";
    // string r = "", m = "bba";
    string r = "aab", m = "ab";

    cout << Solution().canConstruct(r, m) << endl;

    return 0;
}