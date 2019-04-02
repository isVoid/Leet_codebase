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

    // Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
    bool vers[7] = {-1, 0, 0, 0, 0, 0, 1};
    if (version <= 6)
        return vers[version];
    else
        return true;
}

class Solution {
public:

    //4ms 100%
    //8MB 91.73%
    int binS(long a, long b) {
        while (a <= b) {
            long c = (a + b) / 2;
            if (isBadVersion(c)) {
                b = c-1;
            }
            else {
                a = c+1;
            }
        }
        return a;
    }

    int firstBadVersion(int n) {
        return binS(1, n);
    }
}; 

int main(int argc, char ** argv) {

    Solution s;

    for (int i = 6; i < 1000; i++) {
        if (s.firstBadVersion(i) != 6) {
            cout << "Failed! at: " << i << endl;
            return -1;
        }
    }
    cout << "Success!" << endl;
    return 0;
}