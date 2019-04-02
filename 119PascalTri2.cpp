#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> p;
        p.push_back(1);
        if (rowIndex == 0) return p;
        p.push_back(1);
        if (rowIndex == 1) return p;

        int c = 1;
        vector<int> n;
        while (c < rowIndex) {
            n.clear();
            n.push_back(1);
            for (int i = 0; i <= p.size() - 2; i++) {
                n.push_back(p[i] + p[i+1]);
            }
            n.push_back(1);
            p = vector<int>(n);
            c++;
        }
        
        return n;
    }
};

int main () {

    int l = 0;
    Solution s;
    vector<int> g = s.getRow(l);

    cout << '[';
    for (auto j:g) {
        cout << j << ", ";
    }
    cout << "]\n";


    return 0;
}