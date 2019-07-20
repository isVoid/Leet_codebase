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

struct pNode {
    int unused;
    int unclosed;
    string parens;

    pNode(int uu, int uc, string p) : unused(uu), unclosed(uc), parens(p) {}
};

class Solution {
public:

    vector<string> ans;
    void helper(pNode n) {
        if (n.unused == 0 && n.unclosed == 0) {
            ans.push_back(n.parens);
            return;
        }

        if (n.unused != 0) {
            pNode next(n);
            next.parens += "(";
            next.unused--;
            next.unclosed++;
            helper(next);
        }

        if (n.unclosed != 0) {
            pNode next(n);
            next.parens += ")";
            next.unclosed--;
            helper(next);
        }

    }

    // 53.57% 12ms
    // 18.6MB 12.24%
    vector<string> generateParenthesis(int n) {
        if (n == 0) return ans;

        pNode p(--n, 1, "(");
        helper(p);
        return ans;
    }

    //7.74% 24ms
    //15.4MB 69.01%
    // vector<string> generateParenthesis(int n) {
    //     vector<string> ans;

    //     if (n == 0) {
    //         ans.push_back("");
    //         return ans;
    //     }

    //     for (int i = 0; i < n; i++) {
    //         for (auto left : generateParenthesis(i)) {
    //             for (auto right : generateParenthesis(n - 1 - i)) {
    //                 ans.push_back("(" + left + ")" + right);
    //             }
    //         }
    //     }
    //     return ans;
    // }
};

int main(int argc, char ** argv) {

    vector<string> a = Solution().generateParenthesis(2);
    printVector(a);

    return 0;
}