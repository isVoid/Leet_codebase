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

    void n2b(int n, int &k, long long &s) {
        k = 1;
        s = 0;
        long long sk = 9;
        long long t = 10;
        
        while (sk < n) {
            s = sk;
            t *= 10;
            k++;
            sk = k * t - (t - 1) / 9;
        }
        k--;
    }

    int findNthDigit(int n) {
        long long Sk_1;
        int k;
        n2b(n, k, Sk_1);
        int r = n - Sk_1 - 1;
        
        int a = r / (k+1);
        int b = r % (k+1);

        int i = a + pow(10, k);
        // cout << i << " " << b << " ";
        for (int j = 0; j < k - b; j++) {
            i /= 10;
        }
        return i % 10;

    }
};

int main(int argc, char ** argv) {

    // int n = 100;
    int n = 15;

    cout << Solution().findNthDigit(n) << endl;

    return 0;
}