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
#include <bitset>
#include "dbg.hpp"
using namespace std;

struct ListNode;
struct TreeNode;
class Solution {
public:

    //4ms 73.79%
    //8.2MB 21.26%
    int getSum(int a, int b) {
        bitset<32> m(a), n(b), c(0);
        cout << m << endl;
        cout << n << endl;
        bool carry = 0;
        for (int i = 0; i < 32; i++) {
            c[i] = m[i] ^ n[i] ^ carry;
            carry = (m[i] & n[i]) | (m[i] & carry) | (n[i] & carry);
        }
        cout << c << endl;
        int ans = (int)c.to_ulong();

        return ans;
    }
};

int main(int argc, char ** argv) {

    // bitset<32> bs(-2);
    // cout << bs << endl;
    // cout << bs.size() << endl;
    // cout << bs.count() << endl;
    // cout << bs.test(0) << endl;
    // cout << bs.test(1) << endl;
    // cout << bs[0] << endl;
    // cout << bs[1] << endl;

    // int a = -1, b = 2;
    int a = -101, b = 200;

    cout << Solution().getSum(a, b) << endl;

    return 0;
}