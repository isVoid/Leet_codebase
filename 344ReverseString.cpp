#include <iostream>
#include <vector>
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
    //52ms 98.84%
    //15.1MB 100%
    void reverseString(vector<char>& s) {
        for(size_t i = 0; i < s.size() / 2; i++)
        {
            int j = s.size() - i - 1;
            swap(s[i], s[j]);
        }
    }
};

int main(int argc, char ** argv) {

    // char string[] = {'h', 'e', 'l', 'l', 'o'};
    // char string[] = {'h', 'e', 'l', 'l'};
    // char string[] = {'h'};
    char string[] = {};
    vector<char> v(string, string + sizeof(string) / sizeof(char));

    Solution().reverseString(v);
    printVector(v);

    return 0;
}