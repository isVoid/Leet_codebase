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
    // //8ms 29.64%
    // //8.6MB 11.24%
    // bool divisorGame(int N) {
    //     vector<int> dp = {false, false, true, false, true}; //0, 1, 2, 3, 4

    //     for (int i = 5; i <= N; i++) {
    //         bool n = false;
    //         for (int j = 1; j < i; j++) {
    //             if (i % j == 0) {
    //                 if (dp[i-j] == false) {
    //                     n = true;
    //                 }
    //             }
    //         }
    //         dp.push_back(n);
    //     }

    //     printVector(dp);
    //     return dp[N];
    // }

    //4ms 95.13%
    //8.3MB 21.07%
    bool divisorGame(int N) {
        // vector<int> dp = {false, false, true, false, true}; //0, 1, 2, 3, 4

        if (N == 0) return false;
        if (N % 2 == 0) return true;
        else return false;
    }
};

int main(int argc, char ** argv) {

    int N = 1000;

    cout << Solution().divisorGame(N) << endl;

    return 0;
}