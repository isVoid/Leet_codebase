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
class Solution {
public:

    template<class Iter, class T>
    Iter binary_find(Iter begin, Iter end, T val)
    {
        // Finds the lower bound in at most log(last - first) + 1 comparisons
        Iter i = std::lower_bound(begin, end, val);

        if (i != end && !(val < *i))
            return i; // found
        else
            return end; // not found
    }

    vector< vector<int> > threeSum(vector<int>& n) {
        vector< vector<int> > totalResult;
        vector< vector<int> > idxes;
        sort(n.begin(), n.end());

        int *hash = new int[65536];
        memset(hash, 0, 65536);

        for (int i = 0; i < n.size(); i++) {
            for (int j = i + 1; j < n.size(); j++) {
                vector<int> result;
                vector<int> idx;
                int sum = -(n[i] + n[j]);
                int tmp1 = n[i], tmp2 = n[j];
                n.erase(n.begin() + i);
                n.erase(n.begin() + j - 1);
                vector<int>::iterator iter = binary_find(n.begin(), n.end(), sum);
                
                if (iter != n.end()) {

                    result.push_back(tmp1);
                    result.push_back(tmp2);
                    result.push_back(*iter);

                    idx.push_back(i);
                    idx.push_back(j);
                    idx.push_back(iter - n.begin());

                    sort(idx.begin(), idx.end());
                    
                    if (find(idxes.begin(), idxes.end(), idx) == idxes.end()) {
                        totalResult.push_back(result);
                        idxes.push_back(idx);
                    }
                }
                n.insert(n.begin() + i, tmp1);
                n.insert(n.begin() + j, tmp2);
            }
        }

        delete[] hash;
        return totalResult;
    }
};

int main(int argc, char ** argv) {

    int a[] = {-1, 0, 1, 2, -1, -4};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    // printVector(v);
    // v.erase(v.begin() + 3);
    // v.erase(v.begin() + 5 - 1);
    // printVector(v);
    // v.insert(v.begin() + 3, 5);
    // v.insert(v.begin() + 5, 6);
    // printVector(v);

    vector< vector<int> > r = Solution().threeSum(v);
    for (auto rv : r) {
        printVector(rv);
    }

    return 0;
}