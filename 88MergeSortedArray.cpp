#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 4ms 98%
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            int a = 0, b = m - 1;
            while (a < b) {
                int c = (a+b) / 2;
                if (nums1[c] < nums2[i]) {
                    a = c + 1;
                }
                else if (nums1[c] > nums2[i]) {
                    b = c - 1;
                }
                else {
                    a = b = c;
                }
            }

            // cout << a << " " << b << " ";
            // // int c = b < a ? b+1 : a;
            // cout << nums2[i] << " " << nums1[a] << endl;
            if (nums2[i] > nums1[a] && a < m) a = a + 1;
            for (int j = m; j > a; j--) {
                nums1[j] = nums1[j - 1];
            }
            nums1[a] = nums2[i];
            m++;

            // for (int i = 0; i < nums1.size(); i++) {
            //     cout << nums1[i] << " ";
            // }
            // cout << endl;
        }
    }
};

int main() {

    vector<int> l, r;
    int m = 3, n = 3;
    l.push_back(1);
    l.push_back(5);
    l.push_back(6);
    l.push_back(0);
    l.push_back(0);
    l.push_back(0);

    r.push_back(2);
    r.push_back(2);
    r.push_back(3);

    Solution s;
    s.merge(l, m, r, n);
    cout << "result:" << endl;
    for (int i = 0; i < m+n; i++) {
        cout << l[i] << " ";
    }
    cout << endl;

    return 0;
}