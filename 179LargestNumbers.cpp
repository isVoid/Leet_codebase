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

bool compare(const string &a, const string &b) {
    string aa = a + b;
    string bb = b + a;
    return aa > bb;
}

struct ListNode;
struct TreeNode;
class Solution {
public:   

    string int2string(int n) {
        if (n == 0) return "0";
        stack<char> stk;
        string ans = "";
        while (n > 0) {
            stk.push(n % 10 + '0');
            n /= 10;
        }
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> ns;
        string ans;
        for (int n : nums) {
            ns.push_back(int2string(n));
        }
        sort(ns.begin(), ns.end(), compare);
        if (ns[0] == "0") return "0";
        for (string s : ns) {
            ans += s;
        }
        return ans;
    }
};

int main(int argc, char ** argv) {

    // string a = "10", b = "2";
    // vector<string> v = {a, b};
    // // cout << Solution().compare(a, b) << endl;
    // sort(v.begin(), v.end(), greater<string>());

    // printVector(v);

    // int a = 10086;
    // cout << Solution().int2string(a) << endl;

    // vector<int> v = {10, 2};
    vector<int> v = {3, 30, 34, 5, 9};
    // vector<int> v = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // vector<int> v = {128, 12};
    // vector<int> v = {0, 0};
    cout << Solution().largestNumber(v) << endl;

    return 0;
}