#include <iostream>
#include <array>
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

    //Manacher
    //For a palindrome centered at C and right bounded at R,
    //the longest palindrome length(LPL) at position on the right 
    //is at least the length on its mirror on the left.
    //If LPL on the left extends beyond the left boundary L,
    //the LPL on its mirror on the left cannot go beyond R, thus
    //it should be R-i
    //When expanding from i, only need to expand from the computed
    //LPL
    //When the new right bound of i goes beyond R, update center C
    //and right bound R.
    //8ms 97.97%
    //9,8MB 65.25%
    string longestPalindrome(string s) {
        if (s=="") return "";

        string decor = "$!";
        for (int i = 0; i < s.length()-1; i++) {
            decor += s[i];
            decor.append("!");
        }
        decor += s[s.length()-1];
        decor.append("!@");

        int C = 1, R = 1, L = 0;
        int mirror;
        int l = decor.length();
        int *p = new int[l];
        for (int i = 0; i < decor.length(); i++) {
            p[i] = 0;
        }

        int mxlpl = -1;
        int mxlppos = -1;

        for (int i = 1; i < decor.length(); i++) {
            mirror = 2 * C - i;
            cout << i << " " << mirror << " " << C << " " << R << " " << L << endl;
            
            if (i < R) {
                //if left palin is within L-bound
                if (mirror - p[mirror] >= L) {
                    p[i] = p[mirror];
                }
                //if left palin is out of L-bound
                else if (mirror - p[mirror] < L) {
                    p[i] = R - i;
                }
            }
            
            cout << "current p[i] " << p[i] << endl;
            //expand from center
            while (decor[i - (p[i] + 1)] == decor[i + (p[i] + 1)]) {
                p[i]++;
            }
            cout << "after update: " << p[i] << endl;

            if (p[i] > mxlpl) {
                mxlpl = p[i];
                mxlppos = i;
            }

            //update center if new right bound is beyond
            if (i + p[i] > R) {
                C = i;
                R = C + p[i];
                L = C - p[i];
            }
        }

        cout << "decor: " << decor << endl;
        cout << "p[]: ";
        for (int i = 0; i < decor.length(); i++) {
            cout << p[i] << " ";
        }
        cout << endl;
        cout << "Max lpl: " << mxlpl << " " << mxlppos << endl;
        string lpdecor = decor.substr(mxlppos-mxlpl, 2*mxlpl);
        string lp;
        for (int i = 0; i < lpdecor.length(); i++) {
            if (lpdecor[i] != '$' && lpdecor[i] != '!' && lpdecor[i] != '@') {
                lp += lpdecor[i];
            }
        }

        delete[] p;
        return lp;
    }

    // //104ms, 43.49
    // //104.1MB, 25.44
    // //Expand from center | DP
    // string longestPalindrome(string s) {
    //     if (s == "") return "";

    //     int l = 0, h = 0;
    //     for (int i = 0; i < s.length(); i++) {
    //         int len1 = expandFromCenter(s, i, i);
    //         int len2 = expandFromCenter(s, i, i+1);
    //         int len = max(len1, len2);

    //         if (len > h - l) {
    //             l = i - (len - 1) / 2;
    //             h = i + len / 2;
    //         }
    //     }
    //     return s.substr(l, h-l+1);
    // }

    // int expandFromCenter(string s, int l, int h) {
    //     if (s[l] != s[h]) return 0;
    //     while (l >= 0 && h < s.length() && s[l] == s[h]) {
    //         l--;
    //         h++;
    //     }
    //     return h-l-1;
    // }

};

int main(int argc, char ** argv) {

    // string t = "abababa";
    // string t = "babad";
    // string t = "";
    string t = "a";
    // string t = "cbbd";
    // string t = "abcd";
    // string t = "adbcbeaff";
    // string t = "adbcbasdfjisvjxcoipvnjsdoinvjlkcxdnjdvhklucAHxbkbsduhvlisdzbaabbbbaahvliudfkghxequifuhiuxstring t = adbcbeaff;ygvlkdfgheaff";
    // string t = "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc";
    // string t = "cbbd";

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

// int maxL;
// string longest;

// struct Pld{
//     string str;
//     int l;
//     int h;
//     Pld(string _str, int _l, int _h):str(_str), l(_l), h(_h) {
//         if (_str.length() > maxL) {
//             maxL = _str.length();
//             longest = _str;
//         }
//     }

//     Pld(char _c, int _l, int _h) {
//         string _str(1, _c);
//         str = _str;
//         l = _l;
//         h = _h;
//         if (_str.length() > maxL) {
//             maxL = _str.length();
//             longest = _str;
//         }
//     }
// };

// queue<Pld> dict;


//   //dp
//     //a palindrome, added with same letter on both end, is also palindrome
//     //establish table to store all palindromes of length l
//     //for each item in table, find expanded palindrome, store at level l+1
//     //
//     //O(n^2) time
    
//     string longestPalindrome(string s) {
//         if (s == "") return "";

//         maxL = 0;
//         longest = "";
//         //init 1 letter
//         for (int i = 0; i < s.length(); i++) {
//             dict.push(Pld(s[i], i, i));
//         }
//         //init 2 letter
//         for (int i = 0; i < s.length()-1; i++) {
//             if (s[i] == s[i+1]) {
//                 Pld p(s.substr(i, 2), i, i+1);
//                 dict.push(p);
//             }
//         }

//         while (!dict.empty()) {
//             //dp core
//             Pld p = dict.front();
//             dict.pop();
//             if (p.l > 0 && p.h < s.length()) {
//                 p.l--;
//                 p.h++;
//                 if (s[p.l] == s[p.h]) {
//                     Pld np = Pld(s.substr(p.l, p.str.length() + 2), p.l, p.h);
//                     dict.push(np);
//                 }
//             }
//         }
//         return longest;
//     }