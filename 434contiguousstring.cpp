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
    //0ms 100%
    //8,6MB 22.61%
    //Look ahead pointer to determine position of next segment
    //Boundary: left end word? right end word? both are not counted by look ahead.
    int countSegments(string s) {
        if (s.length() == 0) return false;

        //left boundary
        int cnt = s[0] == ' ' ? 0 : 1;
        for (int i = 0; i < s.length();) {
            int j = i;
            while (s[j] == ' ') j++;
            //right boundary ( j<s.length() )
            if (j != i && j < s.length()) {
                cnt++;
                i = j;
            }
            else {
                i++;
            }
        }
        return cnt;
    }
};

int main(int argc, char ** argv) {
    string s = "Hello, my name is John";
    // string s = "         ";
    // string s = ", , , ,        a, eaefa";

    cout << Solution().countSegments(s) << endl;
    return 0;
}