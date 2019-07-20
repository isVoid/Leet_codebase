#include <iostream>
#include <vector>
#include <tuple>
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
    int trap(vector<int>& height) {
        int ptr1 = 0, ptr2 = 0;
        int rain = 0;

        while (ptr1 < height.size()) {
            //Search for the "right edge" of next peak
            while (ptr1 + 1 < height.size() && height[ptr1] <= height[ptr1+1])
                ptr1++;
            
            ptr2 = ptr1;

            //Downhill
            while (ptr2 + 1 < height.size() && 
                    (height[ptr2] >= height[ptr2+1]))
                    ptr2++;

            //Did not even get to go up, sequence ends
            if (ptr2 == height.size()-1) break;
            
            //Search for next bucket plank
            int prevPeakIdx = ptr2;
            while (ptr2 < height.size() && 
                    (height[ptr2] < height[ptr1])) {
                        if (height[ptr2] >= height[prevPeakIdx]) {
                            prevPeakIdx = ptr2;
                        }
                        ptr2++;
                    }
            if (ptr2 == height.size()) {
                ptr2 = prevPeakIdx;
            }        
            
            int nextEdge = ptr2;
            int shortestBucket = min(height[ptr1], height[ptr2]);

            //Copmute upper bound of rain
            rain += shortestBucket * (ptr2-ptr1-1);

            //Carve
            ptr1++;
            while (ptr1 < ptr2) {
                rain -= min(shortestBucket, height[ptr1]);
                ptr1++;
            }
        }

        return rain;
    }
};

int main(int argc, char ** argv) {

    // vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2 ,1};
    // vector<int> heights = {6, 5, 2, 0, 0, 0, 0, 0, 1, 3, 3, 3};
    vector<int> heights = {5,2,1,2,1,5};

    cout << Solution().trap(heights) << endl;


    return 0;
}