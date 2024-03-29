#include <iostream>
using namespace std;

class Solution {
public:
    int charToVal(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return -1;
        }
    }
    
    int romanToInt(string s) {
        int n = 0;
        for (int i = 0; i < s.length(); i++) {
            int curN = 0;
            bool sub = false;
            if (i < s.length() - 1) {
                // Look ahead
                char curChar = s[i];
                char nextChar = s[i+1];
                if (curChar == 'I' && (nextChar == 'V' || nextChar == 'X')) {
                    sub = true;
                }
                if (curChar == 'X' && (nextChar == 'L' || nextChar == 'C')) {
                    sub = true;
                }
                if (curChar == 'C' && (nextChar == 'D' || nextChar == 'M')) {
                    sub = true;
                }
            }
            if (sub == true) {
                curN = charToVal(s[i+1]) - charToVal(s[i]);
                i = i+1;
            }
            else {
                curN = charToVal(s[i]);
            }
            
            n = n + curN;
        }
        
        return n;
    }
};

int main() {

    Solution s;
    string input = "LVIII";

    cout << "input as " + input + " " << s.romanToInt(input) << endl;
    
}