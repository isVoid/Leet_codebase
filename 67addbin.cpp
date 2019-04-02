#include <iostream>
using namespace std;

class Solution {
public:
    // 4ms 98.96%
    string addBinary(string a, string b) {
        bool carry = false;
        size_t len = a.length() > b.length() ? a.length() : b.length();
        // pad
        if (a.length() < len) {
            a = string(len - a.length(), '0') + a;
        }
        if (b.length() < len) {
            b = string (len - b.length(), '0') + b;
        }

        string r = string(len, '0');
        for (int i = len - 1; i >= 0; i--) {
            if (carry) {
                r[i] = r[i] + 1;
            }
            r[i] = r[i] + a[i] + b[i] - 2*'0';
            if (r[i] >= '2') {
                carry = true;
                r[i] = r[i] - 2;
            }
            else {
                carry = false;
            }
        }
        if (carry) {
            r = '1' + r;
        }
        return r;
    }
};

int main() {

    string a = "1010";
    string b = "1011";
    // 10101

    Solution s;
    string r = s.addBinary(a, b);
    cout << "result: " << r << endl;

    return 0;
}