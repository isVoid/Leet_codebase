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

    // void debug(int p, int t, bool odd, string& trace) {
    //     trace = trace + "+" + to_string(p);
    //     cout << trace << "=" << to_string(p+t)  << endl;

    //     if (odd) {
    //         printf("Current step: P1\n");
    //         printf("Current total: %d, current placing %d\n", t, p);
    //     }
    //     else {
    //         printf("Current step: P2\n");
    //         printf("Current total: %d, current placing %d\n", t, p);
    //     }
    // }

    // int n;

    // bool helper(int p, int t = 0, bool odd = true, string trace = "") {
        
    //     debug(p, t, odd, trace);

    //     t = t + p;
    //     if (t > n) {
    //         return false;
    //     }
    //     if (t == n && odd) {
    //         return true;
    //     }
    //     else if (t == n && !odd) {
    //         return false;
    //     }

    //     odd = !odd;
    //     if (!odd) {
    //         //next step is p2
    //         helper(1, t, odd, trace);
    //         helper(2, t, odd, trace);
    //         helper(3, t, odd, trace);
    //     }
    //     else {
    //         //next step is p1
    //         return helper(1, t, odd, trace) || helper(2, t, odd, trace) || helper(3, t, odd, trace);
    //     }
        
    // }

    
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};

int main(int argc, char ** argv) {

    int n = 8;

    printf("Result: %d\n", Solution().canWinNim(n));

    return 0;
}