#include <iostream>
#include <vector>
#include <stack>
#include <set>
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
    // 8.1MB 100%
    string convertToTitle(int n) {
        string s = "";

        while (n > 26) {
            int r = n % 26;
            if (r == 0) r = 26;
            s = char('A' + r - 1) + s;
            n = (n - r) / 26;
        }
        s = char('A' + n - 1) + s;

        return s;
    }
};

int main() {

    int a = 701;
    Solution s;
    cout << s.convertToTitle(a) << endl;

    return 0;
}