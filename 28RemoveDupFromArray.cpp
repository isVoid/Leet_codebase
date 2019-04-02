#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            vector<int>::iterator lh = it;
            for (; lh != nums.end(); lh++) {
                if (*lh != *it) {
                    break;
                }
            }
            if (it != lh) {
                nums.erase(it+1, lh);
            }
        }
        return nums.size();
    }
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);


    Solution s;
    s.removeDuplicates(v);

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}