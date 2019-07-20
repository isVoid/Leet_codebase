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
    //9MB 8.57%
    int numDecodings(string s) {
        if (s.length() == 0) return 0;
        if (s[0] == '0') return 0;
        if (s.length() == 1) return 1;

        vector<unsigned long> w = {1};
        if ((s[0] == '1' && s[1] != '0') || (s[0] == '2' && (s[1] >= '1' && s[1] <= '6'))) w.push_back(2);
        else if (s[1] == '0' && s[0] != '1' && s[0] != '2') return 0;
        else w.push_back(1);

        // vector<unsigned long> w = {1};
        // if ((s[0] == '1' && s[1] != '0') || (s[0] == '2' && (s[1] >= '1' && s[1] <= '6'))) w.push_back(2);
        // else if (s[0] == '1' && s[1] == '0') w.push_back(1);

        for (int i = 2; i < s.length(); i++) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') w.push_back(w[i-2]);
                else return 0;
            }
            else if ((s[i-1] == '1') || 
                (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                    w.push_back(w[i-1] + w[i-2]);
            }
            else {
                w.push_back(w[i-1]);
            }
        }
        // printVector(w);
        return w.back();
    }
};

int main(int argc, char ** argv) {

    // string s = "112";
    // string s = "226";
    // string s = "12";
    // string s = "127";
    // string s = "1162";
    // string s = "0123";
    // string s = "1";
    // string s = "";
    // string s = "32";
    // string s = "12";
    // string s = "19";
    // string s = "1";
    // string s = "0";
    // string s = "8";
    // string s = "10";
    // string s = "101";
    // string s = "100";
    // string s = "110";
    // string s = "111";
    // string s = "230";
    string s = "301";

    cout << Solution().numDecodings(s) << endl;

    return 0;
}