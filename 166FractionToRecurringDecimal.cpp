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
class Solution {
public:

    string fractionToDecimal(int n, int d) {
        
        if (n == 0) return "0";
        
        unordered_map<int, int> past_remainders;
        string ans;
        int sign = n > 0 ^ d > 0 ? -1 : 1;
        if (sign < 0)
            ans = '-';

        long numerator = abs(n);
        long denominator = abs(d);

        ans += to_string(numerator / denominator);
        int remainder = numerator % denominator;
        if (remainder == 0) {
            return ans;
        }
        else {
            ans += '.';
        }

        while (remainder) {
            if (past_remainders.find(remainder) != past_remainders.end()) {
                ans.insert(past_remainders.at(remainder), 1, '(');
                ans += ')';
                return ans;
            }
            past_remainders[remainder] = ans.size();

            remainder *= 10;

            ans += to_string(remainder / denominator);
            remainder %= denominator;
        }

        return ans;

    }
};

int main(int argc, char ** argv) {

    // int a = 112, b = 13;
    int a = 1, b = 2;

    cout << Solution().fractionToDecimal(a, b) << endl;

    return 0;
}