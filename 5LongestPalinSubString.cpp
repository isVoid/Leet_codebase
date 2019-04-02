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

int maxL;
string longest;

struct Pld{
    string str;
    int l;
    int h;
    Pld(string _str, int _l, int _h):str(_str), l(_l), h(_h) {
        if (_str.length() > maxL) {
            maxL = _str.length();
            longest = _str;
        }
    }

    Pld(char _c, int _l, int _h) {
        string _str(1, _c);
        str = _str;
        l = _l;
        h = _h;
        if (_str.length() > maxL) {
            maxL = _str.length();
            longest = _str;
        }
    }
};

queue<Pld> dict;

class Solution {
public:

    //dp
    //a palindrome, added with same letter on both end, is also palindrome
    //establish table to store all palindromes of length l
    //for each item in table, find expanded palindrome, store at level l+1
    //
    //O(n^2) time
    
    string longestPalindrome(string s) {
        if (s == "") return "";

        maxL = 0;
        longest = "";
        //init 1 letter
        for (int i = 0; i < s.length(); i++) {
            dict.push(Pld(s[i], i, i));
        }
        //init 2 letter
        for (int i = 0; i < s.length()-1; i++) {
            if (s[i] == s[i+1]) {
                Pld p(s.substr(i, 2), i, i+1);
                dict.push(p);
            }
        }

        while (!dict.empty()) {
            //dp core
            Pld p = dict.front();
            dict.pop();
            if (p.l > 0 && p.h < s.length()) {
                p.l--;
                p.h++;
                if (s[p.l] == s[p.h]) {
                    Pld np = Pld(s.substr(p.l, p.str.length() + 2), p.l, p.h);
                    dict.push(np);
                }
            }
        }
        return longest;
    }
};

int main(int argc, char ** argv) {

    // string t = "babab";
    // string t = "";
    // string t = "a";
    // string t = "cbbd";
    // string t = "abcd";
    // string t = "adbcbeaff";
    // string t = "adbcbasdfjisvjxcoipvnjsdoinvjlkcxdnjdvhklucAHxbkbsduhvlisdzbaabbbbaahvliudfkghxequifuhiuxstring t = adbcbeaff;ygvlkdfgheaff";
    string t = "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc";

    // cout << Solution().isPalindrome(t) << endl;
    cout << Solution().longestPalindrome(t) << endl;

    return 0;
}


//Brute force O(n^3)
//Time Limit Exceeded
// bool isPalindrome(string s) {
//     return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
// }

// string longestPalindrome(string s) {
//     string lp;
//     int l = 0;
//     for (; l <= s.length(); l++) {
//         cout << "l = " << l << endl;
//         for (int i = 0; i+l <= s.length(); i++) {
//             string ss = s.substr(i, l);
//             cout << ss << " ";
//             if (isPalindrome(ss)) {
//                 lp = ss;
//                 break;
//             }
//         }
//         cout << endl;
//     }
//     return lp;
// }