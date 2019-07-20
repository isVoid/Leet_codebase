#include <iostream>
#include <vector>
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
    //16ms 95.28%
    //10.1MB 100%
    string convert(string s, int r) {
        string str;
        int g1 = ceil(s.length() / float(r));
        int g2 = 2*r - 2;
        if (r == 1) g2 = 1;
        
        for (int j = 0; j < r; j++) {
            for (int i = 0; i < g1; i++) {

                //first subgroup
                int idx = i * g2 + j;
                if (idx < s.length()) 
                    str += s[i * g2 + j];
                //second subgroup
                int k = g2 - j;
                int idx2 = i * g2 + k;
                if (k > g2 / 2 && k < g2 && idx2 < s.length()) {
                    str += s[idx2];
                }
            }
        }
        return str;
    }
};

int main(int argc, char ** argv) {

    // string a = "abcdefghijklmn";
    // string a = "";
    // string a = "salkdfjcnklsdhbvlksndfiucgndhlikfbuzlkcxghrliducnghldksrubyclskdngcxkljsdbyvlzkxgilusybckudsfbckjsdnxlkdsybgcldkfbhvlkxchbkdsurcgbklusddblsdkhvnlkdfhbkldfnfkjxchcbvkusernclkesrdhcg";
    // string a = "PAYPALISHIRING";
    // string a = "AB";
    string a = "ABC";
    int n = 2;

    cout << Solution().convert(a, n) << endl;

    return 0;
}