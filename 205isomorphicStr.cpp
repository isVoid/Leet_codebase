#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include "dbg.hpp"
using namespace std;

struct ListNode;

class BiMap {
    map<char, char> AB;
    map<char, char> BA;

public:
    void insert(char a, char b) {
        AB[a] = b;
        BA[b] = a;
    }

    bool notExists(char a, char b) {
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

    char getB(char a) {
        try
        {
            return AB[a];
        }
        catch(const std::out_of_range& e)
        {
            return '-';
        }
    }

    char getA(char b) {
        try
        {
            return BA[b];
        }
        catch(const std::out_of_range& e)
        {
            return '-';
        }
    }

    bool match(char a, char b) {
        char aa = getA(b);
        char bb = getB(a);

        return aa == a && bb == b;
    }

};

class Solution {
public:
    //20ms 14.95%
    //9.7MB 5.26%
    bool isIsomorphic(string s, string t) {
        BiMap bm;
        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            if (bm.notExists(s[i], t[i])) {
                bm.insert(s[i], t[i]);
            }
            else {
                if (!bm.match(s[i], t[i]))
                    return false;
            }
        }
        
        return true;
    }
};

int main(int argc, char ** argv) {

    string s = "foo", t = "bar";
    Solution ss;

    cout << ss.isIsomorphic(s, t) << endl;

    return 0;
}