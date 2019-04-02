#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include "dbg.hpp"
using namespace std;

class Solution {
public:
    //84ms 52.64%
    //9.9MB 29.47%
    int countPrimes(int n) {
        bool primes[n+1];
        memset(primes, true, n+1);
        primes[0] = false;
        primes[1] = false;

        int count = 0;
        for(int i = 2; i < n; i++)
        {
            if (primes[i]) count++;
            int t = 1;
            int j = i;
            while (j <= n) {
                primes[j] = false;
                t++;
                j = i * t;
            }
            
        }
        
        return count;

    }
};

int main(int argc, char ** argv) {

    int t = 12;
    Solution s;

    cout << s.countPrimes(t) << endl;

    return 0;
}