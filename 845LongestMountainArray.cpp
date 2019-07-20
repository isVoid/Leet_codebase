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
#include <climits>
#include "dbg.hpp"
using namespace std;

struct ListNode;
struct TreeNode;

class Solution {
public:
    //96.34% 24ms
    //100.0% 9.9MB
    int longestMountain(vector<int>& A) {
        if (A.size() < 3) return 0; 

        int a = 1, b = 0, c = 0, m = INT_MIN, cur = 0;
        while (a < A.size()) {
            b = a;
            while (b < A.size() && A[b] > A[b-1]) b++;
            c = b;
            while (c < A.size() && A[c] < A[c-1]) c++;
            if (c > b && b > a)
                cur = c - a + 1;

            m = max(m, cur);
            if (a == c) a = c + 1;
            else a = c;
            cur = 0;
        }

        return m == 1 ? 0 : m;
    }
};

int main(int argc, char ** argv) {

    vector<int> a = {1, 2, 3, 4, 5, 4, 3, 2, 1, 2, 3, 2, 1};
    // vector<int> a = {2,1,4,7,3,2,5};
    // vector<int> a = {2, 2, 2};
    // vector<int> a = {1, 2, 3};
    // vector<int> a = {1, 2, 1};
    // vector<int> a = {9, 8, 7, 6, 5 ,4 ,3, 2, 1};

    cout << Solution().longestMountain(a) << endl;

    return 0;
}