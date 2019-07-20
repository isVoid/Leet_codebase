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
    
    // //112ms 46.53%
    // //15.2MB 18.13%
    // int numSquares(int n) {
    //     vector<int> nsq = {0, 1, 2, 3};
        
    //     for (int i = 4; i <= n; i++) {
    //         nsq.push_back(i);
    //         int j = 1;
    //         int k = j * j;
    //         while (k <= i) {
    //             nsq[i] = min(nsq[i], 1+nsq[i-k]);

    //             j++;
    //             k = j*j;
    //         }
    //     }

    //     return nsq[n];
    // }

    bool isSquared(int n) {
        int k = floor(sqrt(n));
        return k * k == n;
    }

    //Lagrange
    //4ms 99.53%
    //8.2MB 93.56%
    int numSquares(int n) {
        //1
        int k = floor(sqrt(n));
        if (k*k == n) return 1;

        //2
        for (int i = 1; i <= k; i++) {
            if (isSquared(n - i*i)) return 2;
        }

        //4
        //https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem
        while (n % 4 == 0) 
            n = n / 4;
        if ((n - 7) % 8 == 0)
            return 4;

        return 3;
    }
};

int main(int argc, char ** argv) {

    int n = 12;

    cout << Solution().numSquares(n) << endl;

    return 0;
}