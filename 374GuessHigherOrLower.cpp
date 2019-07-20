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

int guess(int num) {
    int t = 6;
    if (num < t) return 1;
    else if (num > t) return -1;
    else return 0;
}

class Solution {
public:
    //4ms 75.55%
    //8.1MB 70.99%
    int guessNumber(int n) {
        long long a = 0, b = n;
        while (a < b) {
            int c = (a + b) / 2;
            if (guess(c) < 0) {
                b = c - 1;
            }
            else if (guess(c) > 0) {
                a = c + 1;
            }
            else {
                return c;
            }
        }

        if (guess(a) == 0) return a;
        else return b;
    }
};
int main(int argc, char ** argv) {

    int n = 10;

    cout << Solution().guessNumber(n) << endl;

    return 0;
}