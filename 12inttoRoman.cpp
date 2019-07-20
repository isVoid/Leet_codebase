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

    //16ms 96.18%
    //8.5MB 98.86%
    string intToRoman(int num) {

        string dict[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM", "??", "?", "??", "???", "????", "??"}};


        int t = num / 1000;
        num = num - t * 1000;
        int h = num / 100;
        num = num - h * 100;
        int te = num / 10;
        num = num - te * 10;
        int d = num;

        string roman;
        roman += dict[3][t];
        roman += dict[2][h];
        roman += dict[1][te];
        roman += dict[0][d];

        return roman;
    }
};

int main(int argc, char ** argv) {

    // int t = 3999;
    // int t = 3888;
    // int t = 1560;
    // int t = 480;
    // int t = 58;
    int t = 3;
    cout << Solution().intToRoman(t) << endl;

    return 0;
}