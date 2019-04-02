#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // 0 no match, 1 part match, 2 full match;
        int state = 0;
        int hsl = haystack.length(), nl = needle.length();
        int hpos = 0, npos = 0;
        int curStart = -1;

        if (needle.length() == 0) {
            return 0;
        }

        while (hpos <= hsl) {

            if (state == 0) {
                cout << "state: " << state << " " << haystack[hpos] << " " << needle[npos] << " " << npos << " " << nl << endl;
                if (haystack[hpos] == needle[npos]) {
                    state = 1;
                    curStart = hpos;
                    npos++;
                }
                hpos++;
            }
            else if (state == 1) {
                cout << "state: " << state << " " << haystack[hpos] << " " << needle[npos] << " " << npos << " " << nl << endl;
                if (npos == nl) {
                    state = 2;
                }
                else if (haystack[hpos] == needle[npos]) {
                    npos++;
                    hpos++;
                }
                else if (haystack[hpos] != needle[npos]) {
                    cout << "reset" << endl;
                    hpos = hpos - npos + 1;
                    npos = 0;
                    state = 0;
                    curStart = -1;
                }
            }
            else if (state == 2) {
                cout << "state: " << state << " " << haystack[hpos] << " " << needle[npos] << " " << npos << " " << nl << endl;
                return curStart;
            }
        }

        return -1;
    }
};

int main() {

    string h =  "aabababa", n = "aba";
    Solution s;
    cout << s.strStr(h, n) << endl;

    return 0;
}