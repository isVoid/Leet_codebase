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
class Solution {
public:

    //4ms 100%
    //8.8MB 31.5%
    void setup(vector< vector<string> >& keys) {

        vector<string> two({"a", "b", "c"});
        vector<string> three({"d", "e", "f"});
        vector<string> four({"g", "h", "i"});
        vector<string> five({"j", "k", "l"});
        vector<string> six({"m", "n", "o"});
        vector<string> seven({"p", "q", "r", "s"});
        vector<string> eight({"t", "u", "v"});
        vector<string> nine({"w", "x", "y", "z"});

        keys.push_back(two);
        keys.push_back(three);
        keys.push_back(four);
        keys.push_back(five);
        keys.push_back(six);
        keys.push_back(seven);
        keys.push_back(eight);
        keys.push_back(nine);
    }

    vector< vector<string> > keys;
    vector<int> digits;

    void press(int at, string parentString, vector<string>& words) {
        if (at == digits.size()) {
            words.push_back(parentString);
            return;
        }

        int n = digits[at];
        if (n < 0 || n > 7) {
            press(at+1, parentString, words);
            return;
        }
        for (int i = 0; i < keys[n].size(); i++) {
            string b = parentString + keys[n][i];
            press(at + 1, b, words);
        }
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> words;

        if (digits == "") return words;

        setup(keys);

        for (int i = 0; i < digits.size(); i++) {
            int k = (int)(digits[i] - '2');
            this -> digits.push_back(k);
        }
        

        press(0, "", words);

        return words;
    }
};

int main(int argc, char ** argv) {

    string d = "";
    // string d = "1";
    // string d = "123*##";
    string d = "63453462543";
    // string d = "12345689";

    vector<string> str = Solution().letterCombinations(d);
    printVector(str);

    return 0;
}