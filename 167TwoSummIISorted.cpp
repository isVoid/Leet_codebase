#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include "dbg.hpp"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // brute
    // 844ms 5.76%
    // 9.5MB
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     vector<int> result;
    //     for(int i = 0; i < numbers.size(); i++)
    //     {
    //         for(int j = i+1; j < numbers.size(); j++)
    //         {
    //             if (numbers[i] + numbers[j] == target) {
    //                 result.push_back(++i);
    //                 result.push_back(++j);
    //                 return result;
    //             }
    //         }
            
    //     }
    //     return result;
    // }

    // 2pointer
    // 8ms 100%
    // 9.6MB
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        vector<int> result;
        while(i < j){
            if (numbers[i] + numbers[j] == target) {
                result.push_back(++i);
                result.push_back(++j);
                break;
            }
            else if (numbers[i] + numbers[j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        
        return result;
    }
};

int main() {

    int arr[] = {2, 7, 11, 15};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(int));
    int target = 26;

    printVector(v);
    printf("Target: %d\n", target);

    Solution s;
    printVector(s.twoSum(v, target));

    return 0;
}