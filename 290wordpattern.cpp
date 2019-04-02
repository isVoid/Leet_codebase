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

class BiMap {
    map<char, string> AB;
    map<string, char> BA;

public:
    void insert(char a, string b) {
        AB[a] = b;
        BA[b] = a;
    }

    bool notExists(char a, string b) {
        bool ab, ba;
        try
        {
            AB.at(a);
            ab = true;
        }
        catch(const std::out_of_range& e)
        {
            ab = false;
        }

        try
        {
            BA.at(b);
            ba = true;
        }
        catch(const std::out_of_range& e)
        {
            ba = false;
        }
        
        return !ab && !ba;
    }

    string getB(char a) {
        try
        {
            return AB[a];
        }
        catch(const std::out_of_range& e)
        {
            return "-";
        }
    }

    char getA(string b) {
        try
        {
            return BA[b];
        }
        catch(const std::out_of_range& e)
        {
            return '-';
        }
    }

    bool match(char a, string b) {
        char aa = getA(b);
        string bb = getB(a);

        return aa == a && bb == b;
    }

};

class Solution {
public:

    void nextWord(string& p, string& word) {
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == ' ') {
                word = p.substr(0, i);
                p = p.substr(i+1);
                return;
            }
        }
        word = p;
        p = "";
    }

    vector<string> splitWord(string p) {
        vector<string> words;
        string word;
        while(p != "") {
            nextWord(p, word);
            words.push_back(word);
        }
        return words;
    }

    //4ms 100%
    //9.5MB 5.56%
    bool wordPattern(string pattern, string str) {
        BiMap dict;
        vector<string> words = splitWord(str);

        if (words.size() != pattern.length()) {
            cout << "size mismatch" << endl;
            return false;
        }
        
        for (int i = 0; i < pattern.length(); i++) {
            char k = pattern[i];
            string word = words[i];

            cout << k << " | " << word << " | " << str << endl;

            if (dict.notExists(k, word)) {
                cout << "add new entry" << endl;
                dict.insert(k, word);
            }
            else {
                if (!dict.match(k, word)) {
                    cout << "mismtach" << endl;
                    return false;
                }
                cout << "match" << endl;
            }
        }

        return true;
    }
};

int main(int argc, char ** argv) {

    string pattern = "abba", str = "dog cat cat dog";
    // string pattern = "abba", str = "dog cat cat fish";
    // string pattern = "aaaa", str = "dog cat cat dog";
    // string pattern = "abba", str = "dog dog dog dog";
    // string pattern = "aaa", str = "aa, aa, aa, aa";
    // string pattern = "he", str = "unit";
    
    cout << Solution().wordPattern(pattern, str) << endl;

    return 0;
}