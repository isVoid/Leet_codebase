#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 0ms 100%
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        bool carry = true;
        while (i >= 0) {
            // cout << digits[i] << " ";
            if (carry) {
                digits[i] = digits[i] + 1;
                // cout << "with carry adding " << digits[i] << endl;
            }
            if (digits[i] == 10) {
                carry = true;
                digits[i] = 0;
                // cout << "carry over " << digits[i] << endl;
            }
            else {
                carry = false;
                // cout << "no carry " << digits[i] << endl;
            }
            i--;
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {

    vector<int> d;
    // d.push_back(1);
    // d.push_back(9);
    // d.push_back(0);
    // d.push_back(0);
    // d.push_back(9);
    d.push_back(9);
    Solution s;
    vector<int> r = s.plusOne(d);

    for (vector<int>::iterator it = r.begin(); it != r.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}