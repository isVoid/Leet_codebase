#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {        
        int cnt = 0;
        bool strip = false;
        int i = s.length()-1;
        for (; i>=0; i--) {
            // cout << s[i] << " ";
            if (s[i] != ' ' && !strip) {
                strip = !strip;
                cnt++;
                // cout << "stripped cnt++" << " ";
            }
            else if (strip && s[i] != ' ') {
                cnt++;
                // cout << "cnt++" << " ";
            }
            else if (strip && s[i] == ' ') {
                // cout << "end of last word" << endl;
                break;
            }
            cout << endl;
        }
        return cnt;
    }
};

int main() {

    string s = " ";
    Solution so;
    cout << so.lengthOfLastWord(s) << endl;

    return 0;
}