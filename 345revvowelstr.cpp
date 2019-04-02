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

    bool isVwl(char a) {
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' ||
        a == "A" || a == 'E' || a == 'I' || a == 'O' || a == 'U';
    }

    void mySwap(char& a, char& b) {
        char c = a;
        a = b;
        b = c;
    }

    //12ms 98.02%
    //9.9MB 42.78%
    string reverseVowels(string s) {
        if (s == "") return s;
        int a = 0, b = s.length() - 1;
        for(;;) {
            while (!isVwl(s[a]) && a < s.length()){
                a++;
            }
            while (!isVwl(s[b]) && b >= 0){
                b--;
            } 
            if (a >= b) {
                break;
            }
            cout << a << " " << b << endl;
            char c = s[a];
            s[a] = s[b];
            s[b] = c;

            a++;
            b--;
        }
        return s;
    }
};

int main(int argc, char ** argv) {

    // string t = "hello";
    // string t = "leetcode";
    // string t = "a";
    // string t = "";
    // string t = "aeiou";
    string t = "6V:.z;ID6DI;z.:VH";
    cout << Solution().reverseVowels(t) << endl;

    return 0;
}