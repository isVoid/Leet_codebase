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
    //4ms 100%
    //8.1MB 81.82%
    int addDigits(int num) {
        //See the digital root of a positive integer as the position it 
        //holds with respect to the largest multiple of 9 less than the number itself.
        //Which is modulo:
        return num - 9 * floor((num-1)/9);
    }
};

int main(int argc, char ** argv) {

    int t = 9;
    Solution s;

    cout << s.addDigits(t) << endl;

    return 0;
}