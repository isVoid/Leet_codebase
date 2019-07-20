#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <set>
#include <map>
// #include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include "dbg.hpp"
using namespace std;

struct ListNode;
struct TreeNode;

class PairSum {
public:
    int first;
    int second;
    int sum;

    bool noCommon(const PairSum& other) {
        return first != other.first && first != other.second && 
            second != other.first && second != other.second;
    }

    bool sameNumbers(const PairSum& other, const vector<int>& list) {
        return (list[first] == list[other.first] && 
        list[second] == list[other.second]) || (list[second] == list[other.first] &&
        list[first] == list[other.second]);
    }

    friend bool operator == (const PairSum& p1, const PairSum& p2) {
        return p1.sum == p2.sum;
    }

    friend bool operator < (const PairSum& p1, const PairSum& p2) {
        return p1.sum < p2.sum;
    }

    PairSum(int f, int s, int su) : first(f), second(s), sum(su) {}

    void print(vector<int> list) {
        cout << "First idx: " << first << " First: " << list[first] << " Second idx: " 
            << second << " Second: " << list[second] << " " << sum << endl;
    }
};

class Solution {
public:

    // vector< vector<int> > fourSum(vector<int>& nums, int target) {
    //     // first compute two pair sums n^2
    //     // second find two pairs that sums to target n^2logn
    //     // total n^2logn

    //     vector< vector<int> > res;
    //     if (nums.size() < 4) return res;

    //     sort(nums.begin(), nums.end());

    //     vector<PairSum> pairs;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = i+1; j < nums.size(); j++) {
    //             pairs.push_back(PairSum(i, j, nums[i] + nums[j]));
    //         }
    //     }

    //     // for (int i = 0; i < pairs.size(); i++) {
    //     //     cout << pairs[i].first << " " << pairs[i].second << " " << pairs[i].sum << endl;
    //     // }

    //     sort(pairs.begin(), pairs.end());

    //     // for (int i = 0; i < pairs.size(); i++) {
    //     //     pairs[i].print(nums);
    //     // }

    //     // return res;

    //     int f = 0, b = pairs.size() - 1;
    //     while (f < b) {
    //         int t = pairs[f].sum + pairs[b].sum;
    //         if (t > target) {
    //             b--;
    //         }
    //         else if (t < target) {
    //             f++;
    //         }
    //         else {
    //             // pairs[f].print(nums);
    //             // pairs[b].print(nums);
    //             // cout << f << " " << b << endl;
    //             if (pairs[f].noCommon(pairs[b])) {
    //                 // pairs[f].print(nums);
    //                 // pairs[b].print(nums);
    //                 vector<int> r;
    //                 r.push_back(nums[pairs[f].first]);
    //                 r.push_back(nums[pairs[f].second]);
    //                 r.push_back(nums[pairs[b].first]);
    //                 r.push_back(nums[pairs[b].second]);

    //                 sort(r.begin(), r.end());
    //                 bool exists = false;
    //                 for (auto& i : res) {
    //                     if (i == r) {
    //                         exists = true;
    //                         break;
    //                     }
    //                 }
    //                 if (!exists)
    //                     res.push_back(r);

    //                 // while (f < b && pairs[f].sameNumbers(pairs[f+1], nums)) f++;
    //                 // while (f < b && pairs[b].sameNumbers(pairs[b-1], nums)) b--;
    //             }
    //             f++;
    //         }
    //     }

    //     return res;
    // }

    //16ms 92.53%
    //9.2MB 100%
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        
        vector< vector<int> > result;
        if (nums.size() < 4) return result;

        sort(nums.begin(), nums.end());

        // base pointer
        for (int i = 0; i < nums.size() - 3; i++) {
            //Search finish when the base is too large
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;

            //Skip search when the base is too small
            if (nums[i] + nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) continue;

            //Skip search when the base has been explored
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // second base pointer
            for (int j = i+1; j < nums.size() - 2; j++) {
                //Same pruning as first
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if (nums[i] + nums[j] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) continue;
                if (j > i+1 && nums[j] == nums[j-1]) continue;

                //Two pointer
                int f = j+1;
                int b = nums.size() - 1;
                int basesum = nums[i] + nums[j];
                while (f < b) {
                    if (basesum + nums[f] + nums[b] > target) {
                        b--;
                    }
                    else if (basesum + nums[f] + nums[b] < target) {
                        f++;
                    }
                    else {
                        vector<int> v({nums[i], nums[j], nums[f], nums[b]});
                        result.push_back(v);
                        //skip explored value
                        while (f < b && nums[f] == nums[f+1]) f++;
                        while (f < b && nums[b] == nums[b-1]) b--;
                        //actually move to next value to explore
                        f++;
                        b--;
                    }
                }
            }
        }

        return result;
    }

};

int main(int argc, char ** argv) {

    int target = 0;
    // vector <int> v({-4, -1, -1, -1, 2, 2, 3, 4, -1});
    // vector <int> v({1, 0, -1, 0, -2, 2});
    // vector <int> v({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    vector <int> v = {-4,-3,-2,-1,0,0,1,2,3,4};
    vector< vector<int> > res = Solution().fourSum(v, target);

    for (auto& vv : res) {
        printVector(vv);
    }

    return 0;
}