#include <iostream>
#include <cstdio>
using namespace std;

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 6.     312211
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            string next = "";
            for (int j = 0; j < s.length();) {
                int cnt = 0;
                int k = j;
                for (; k < s.length() && s[k] == s[j]; k++) {
                        cnt++;
                }
                char cnts[1024];
                sprintf(cnts, "%d", cnt);
                next = next + cnts + s[j];
                j = k;
            }
            s = next;
        }
        return s;
    }
};

int main() {

    Solution s;
    for (int n = 1; n < 30; n++) {
        cout << "n:" << n << " " << s.countAndSay(n) << endl;
    }
    
    return 0;
}