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

    vector<char> num2vChar(int n) {
        vector<char> ans;
        while (n != 0) {
            int d = n % 10;
            ans.push_back(d + '0');
            n /= 10;
        }
        return ans;
    }
    
    //8ms 96.23%
    //9.6MB 37.32%
    //接近真实的RLE编码实现
    //注意细节：1. 每个字母重复编码可能大于10
    //2. 题目要求“压缩后长度肯定小于原长” -- 言下之意为重复1次的不需写'1'，重复2次以上的才需要写重复次数。
    int compress(vector<char>& chars) {
        if (chars.empty()) return 0;

        char c = chars[0];
        int cnt = 0;
        int start = 0;
        size_t olen = chars.size();

        for (int i = 0; i < chars.size();) {
            if (chars[i] != c) {
                if (cnt > 1) {
                    vector<char> cntC = num2vChar(cnt);
                    //modify chars
                    // chars.insert(chars.begin()+i, cnt + '0');
                    chars.insert(chars.begin()+i, cntC.rbegin(), cntC.rend());
                    chars.erase(chars.begin()+start+1, chars.begin()+i);
                    i = i - cnt + 1 + cntC.size();
                }
                
                //update c, cnt 
                start = i;
                c = chars[i];
                cnt = 0;
            }
            else {
                cnt++;
                i++;
            }
        }

        if (cnt > 1) {
            vector<char> cntC = num2vChar(cnt);
            chars.insert(chars.end(), cntC.rbegin(), cntC.rend());
            chars.erase(chars.begin()+start+1, chars.end()-cntC.size());
        }

        // chars.resize(min(chars.size(), olen));

        return chars.size();
    }
};

int main(int argc, char ** argv) {

    // vector<char> word = {'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c'};
    // vector<char> word = {'a', 'a', 'b', 'b', 'b', 'b', 'e', 'e', 'e', 'o', 'o', 'o'};
    // vector<char> word = {'a'};

    // vector<char> word = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    vector<char> word = {'a','a','a','a','a','b'};

    cout << Solution().compress(word) << endl;

    printVector(word);

    // int n = 256;
    // printVector(Solution().num2vChar(n));

    return 0;
}