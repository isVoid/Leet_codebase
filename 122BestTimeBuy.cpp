#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0, j = -1;

        int l = prices.size() - 1;
        for (int i = 0; i < l; i++) {
            int lh = prices[i+1];
            if (j == -1) {
                if (lh > prices[i]) {
                    j = i;
                }
            }
            else {
                if (lh < prices[i]) {
                    mp += prices[i] - prices[j];
                    j = -1;
                }
            }
        }
        if (j != -1 && prices[l] >= prices[l-1]) {
            mp += prices[l] - prices[j];
            j = -1;
        }

        return mp;
    }
};

int main() {

    // int p[] = {7, 1, 5, 3, 6, 4};
    // int p[] = {0};
    // int p[] = {5, 4, 3, 2 ,1};
    // int p[] = {};
    // int p[] = {7, 1, 5, 3, 6};
    int p[] = {1,9,6,9,1,7,1,1,5,9,9,9};
    vector<int> ps(p, p+sizeof(p)/sizeof(int));

    Solution s;
    cout << s.maxProfit(ps) << endl;

    return 0;
}