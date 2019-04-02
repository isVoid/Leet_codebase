#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > generate(int numRows) {
        vector< vector<int> > p;
        if (numRows == 0) return p;
        int one[1] = {1};
        p.push_back(vector<int>(one, one + sizeof(one)/sizeof(int)));
        if (numRows == 1) return p;
        int two[2] = {1, 1};
        p.push_back(vector<int>(two, two + sizeof(two)/sizeof(int)));
        if (numRows == 2) return p;

        int c = 2;
        while (c < numRows) {
            vector<int> g;
            g.push_back(1);
            for (int i = 0; i <= p[c-1].size()-2; i++) {
                g.push_back(p[c-1][i] + p[c-1][i+1]);
            }
            g.push_back(1);
            p.push_back(g);
            c++;
        }

        return p;
    }
};

int main () {

    int l = 0;
    Solution s;
    vector< vector<int> > g = s.generate(l);
    for (auto i:g) {
        cout << '[';
        for (auto j:i) {
            cout << j << ", ";
        }
        cout << "]\n";
    }

    return 0;
}