#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <cmath>
#include "dbg.hpp"
using namespace std;

struct ListNode;
struct TreeNode;
class Solution {
public:
    unordered_map<int, bool> dict;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (1+maxChoosableInteger)*maxChoosableInteger/2;
        if(sum < desiredTotal) return false;
        if(desiredTotal <= 0) return true;
        
        return helper(maxChoosableInteger, desiredTotal, 0);
    }

    //564ms 6.49%
    //83.2MB 5.03%
    // bool helper(int n, int t, bitset<32> b) {
    //     cout << n << " " << t << " " << b << endl;
    //     //The other player has won
    //     if (t <= 0) {
    //         return false;
    //     }
    //     //The current game state was not explored
    //     if (dict.find((int)b.to_ulong()) == dict.end()) {
    //         //Traverse every possible state
    //         for (int i = n; i >= 1; i++) {
    //             //Number is not used
    //             if (!b.test(i)) {
    //                 bitset<32> nb(b);
    //                 nb.set(i);
    //                 //explore this state, save true if can win
    //                 if (!helper(n, t - i, nb)) {
    //                     dict.insert({(int)nb.to_ulong(), true});
    //                     return true;
    //                 }
    //             }
    //         }
    //         //explored every state, no possible way to win
    //         dict.insert({(int)b.to_ulong(), false});
    //         return false;
    //     }
    //     else {
    //         return dict.at((int)b.to_ulong());
    //     }
    // }

    //128ms 36.27% (1-n)
    //24.9MB 50.28%
    //---
    //96ms 62.34% (n-1)
    //22MB 72.63%
    bool helper(int n, int t, int used) {
        if (t <= 0) return false;

        if (dict.find(used) != dict.end()) {
            return dict[used];
        }

        for (int i = n; i >= 1; i--) {
            int pick = (1 << i);
            //This number is not picked
            if ((pick & used) == 0) {
                //Pick that number
                if (!helper(n, t-i, used | pick)) {
                    dict.insert({used, true});
                    return true;
                }
            }
        }
        dict.insert({used, false});

        return false;
    }
};

int main(int argc, char ** argv) {

    // int n = 10, t = 12;
    int n = 3, t = 4;

    cout << Solution().canIWin(n ,t) << endl;

    return 0;
}