#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {

public:
/*
    // Hashing function
    // 32ms 12.88%
    // 11.5MB 100%
    int singleNumber(vector<int>& nums) {
        set<int> l;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            set<int>::iterator i_x = l.find(x);
            if (i_x != l.end()) {
                l.erase(i_x);
            }
            else {
                l.insert(x);
            }
        }

        int single = *l.begin();
        return single;
    }
*/

    // XOR
    // 1. a xor a = 0, a xor 0 = a
    // 2. XOR operation is interchangable (order invariant)
    //      a xor b xor a = (a xor a) xor b = b
    // 16ms, 94.61%
    // 9.6MB, 100%
    int singleNumber(vector<int>& nums) {

        int a = 0;
        for (int i = 0; i < nums.size(); i++) {
            a ^= nums[i];
        }
        return a;

    }

};

int main() {

    int n[] = {1, 2, 1, 2, 4};
    // int n[] = {4};
    // int n[] = {9, 9, 8, 8, 7};
    // int n[] = {9, 9, 6, 6, 7, 8, 8};
    vector<int> v(n, n+(sizeof(n) / sizeof(int)));

    Solution s;
    cout << s.singleNumber(v) << endl;

    return 0;
}