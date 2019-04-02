#include <iostream>
using namespace std;

class Solution {
public:
    // 16ms 79.68%
    int mySqrt(int x) {
        long a = 0, b = x;
        while (b >= a) {
            long c = (a+b) / 2;
            if (c * c > x) {
                b = c - 1;
            }
            else if (c * c < x) {
                a = c + 1;
            }
            else {
                return c;
            }
        }
        if (b*b < x) return b;
        else return a;
    }
};

int main() {

    int x = 34;
    Solution s;
    cout << s.mySqrt(x) << endl;

    return 0;
}