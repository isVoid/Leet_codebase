#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int i = 0;
//         int j = nums.size() - 1;

//         if (target < nums[i]) {
//             nums.insert(nums.begin(), target);
//             return i;
//         }
//         if (target > nums[j]) {
//             nums.insert(nums.end(), target);
//             return nums.size()-1;
//         }

//         while (abs(i - j) > 1) 
//         {
//             cout << "i: " << i << " j: " << j << endl;
//             int c = abs(i+j) / 2;
//             if (target > nums[c]) {
//                 i = c;
//             }
//             else if (target < nums[c]) {
//                 j = c;
//             }
//             else {
//                 return c;
//             }
//         }

//         if (target == nums[i]) {
//             return i;
//         }
//         else if (target == nums[j]){
//             return j;
//         }
//         else {
//             nums.insert(nums.begin()+j, target);
//             return j;
//         }
//     }
// };

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) 
        {
            cout << "i: " << i << " " << nums[i] << " j: " << nums[j] << " " << j << endl;
            int c = (i+j) / 2;
            if (target > nums[c]) {
                i = c + 1;
            }
            else if (target < nums[c]) {
                j = c - 1;
            }
            else {
                return c;
            }
        }

        if (target < nums[i]) {
            return i;
        }
        else {
            return j+1;
        }
    }
};

int main() {

    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(6);

    Solution s;
    cout << s.searchInsert(v, 7) << endl;
    cout << "List:" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;


    return 0;
}