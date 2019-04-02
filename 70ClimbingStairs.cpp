#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Recursive function to return gcd of a and b 
    int gcd(int a, int b) 
    { 
        // Everything divides 0  
        if (a == 0) 
        return b; 
        if (b == 0) 
        return a; 
    
        // base case 
        if (a == b) 
            return a; 
    
        // a is greater 
        if (a > b) 
            return gcd(a-b, b); 
        return gcd(a, b-a); 
    } 

    uint64_t comb(int n, int r) {
        // cout << fac(n) << " " << fac(n-x) << " " << fac(x);
        // cout << fac(n, x) << " " << fac(x) << endl;
        // n = 30, r = 15; 30~16 / 15~1
        vector<int> num, den;
        for (int i = n-r+1; i <= n; i++) {
            num.push_back(i);
        }
        for (int i = 1; i <= r; i++) {
            den.push_back(i);
        }

        cout << "After push:" << endl;
        for (int i = 0; i < num.size(); i++) {
            cout << num[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < den.size(); i++) {
            cout << den[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < num.size(); i++) {
            for (int j = 0; j < den.size(); j++) {
                int g = gcd(num[i], den[j]);
                num[i] /= g;
                den[j] /= g;
            }
        }

        cout << "After reduce:" << endl;
        uint64_t p = 1;
        for (int i = 0; i < num.size(); i++) {
            p *= num[i];
            cout << num[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < den.size(); i++) {
            cout << den[i] << " ";
        }
        cout << endl;

        cout << "result:" << endl;
        cout << p << endl << endl;
        // return fac(n, r) / fac(n-r);
        return p;
    }

    int climbStairs(int n) {
        int c = n / 2, x = n - c;
        if (c < x) {
            c++; x--;
        }
        int sum = 0;
        while (x >= 0) {
            cout << c << " " << x << endl;
            // cout << comb(c, x) << endl;
            sum = sum + comb(c, x);
            c++;
            x--;
        }
        return sum;
    }
};

int main() {
    int n = 45;
    Solution s;
    cout << s.climbStairs(n) << endl;

    return 0;
}