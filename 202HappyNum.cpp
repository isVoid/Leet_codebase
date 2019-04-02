#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include "dbg.hpp"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // 4ms 100%
    bool checkCycle(vector<int>& v) {
        if (v.size() & 1) return false;

        for (int i1 = 0; i1 < v.size(); i1++) {
            for (int i2 = i1+1; i2 < v.size(); i2++) {
                if (v[i1] == v[i2]) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isHappy(int n) {
        vector<int> cycle;
        int msdf = 0;
        while (msdf < 50)
        {
            int c = n;
            n = 0;
            while (c != 0) {
                printf("%d^2", c % 10);
                if (c / 10 != 0) {
                    printf(" + ");
                }
                n += pow(c % 10, 2);
                c = c / 10;
            }
            cout << " = " << n << endl;
            if (n == 1) {
                return true;
            }
            else {
                cycle.push_back(n);
                if (checkCycle(cycle))
                    return false;
            }

            msdf++;
        }
        // Impossible
        return false;
    }
};

int main(int argc, char ** argv) {

    int t = 19;
    Solution s;

    cout << s.isHappy(t) << endl;

    return 0;
}