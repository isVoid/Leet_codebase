#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include<algorithm>
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
    //8ms 100%
    //8.1MB
    int titleToNumber(string s) {
        int n = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int j = s.length() - i - 1;
            int d = int(s[i] - 'A' + 1);

            cout << j << " " << d << endl;
            n += pow(26, j) * d;
        }
        return n;
    }
};

int main() {

    string t = "AZ";
    Solution s;

    // cout << pow(26, 0) << endl;
    cout << s.titleToNumber(t) << endl;

    return 0;
}