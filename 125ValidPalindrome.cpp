#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

template<class T>
void printStack(stack<T> stk) {
    stack<T>cpy(stk);
    cout << "Top:: ";
    while(!cpy.empty()) {
        cout << cpy.top();
        cpy.pop();
        if (!cpy.empty()) cout << " -> ";
    }
    cout << " ::Bottom" << endl;
};

class Solution {
public:

    string clean(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
                
            if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= '0' && s[i] <= '9')) {
                s.erase(i, 1);
                i--;
            }
        }
        return s;
    }

    bool isPalindrome(string s) {
        if (s == "") return true;

        string cs = clean(s);
        stack<char> p;
        for (int i = 0; i < cs.length() / 2; i++) {
            p.push(cs[i]);
        }
        for (int i = round(cs.length() / 2.); i< cs.length(); i++) {
            if (cs[i] == p.top()) {
                p.pop();
            }
            else {
                return false;
            }
        }

        return true;
    }
};

int main() {

    // string t = "A man, a plan, a anal: Panama";
    // string t = "race a car";
    // string t = "0P";
    Solution s;
    cout << s.isPalindrome(t) << endl;

    return 0;
}