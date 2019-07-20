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

    string itoa(int n) {
        string s = "";
        while (n != 0) {
            int i = n % 10;
            s = (char)('0' + i) + s;
            n /= 10;
        }
        return s;
    }

    // Runtime: 8 ms, faster than 72.44%
    // Memory Usage: 10.2 MB, less than 80.09%
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        const string f = "Fizz";
        const string b = "Buzz";
        for (int i = 1; i <= n; i++) {
            string s = "";
            if (i % 3 == 0) {
                s += f;
            }
            if (i % 5 == 0) {
                s += b;
            }
            if (s.empty()) {
                s = itoa(i);
            }
            res.emplace_back(s);
        }
        return res;
    }
};

int main(int argc, char ** argv) {

    printVector(Solution().fizzBuzz(15));

    return 0;
}