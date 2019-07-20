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

void printNumber(int x) {cout << x;}

struct ListNode;
struct TreeNode;
class ZeroEvenOdd {
private:
    int n, ke, ko;
    mutex z, e, o;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        if (n&1) {
            ke = n / 2;
            ko = n / 2 + 1;
        }
        else {
            ke = n / 2;
            ko = n / 2;
        }
        e.lock();
        o.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {

        for (int i = 1; i <= n; i++) {
            z.lock();
            printNumber(0);
            if (i&1) {
                o.unlock();
            }
            else {
                e.unlock();
            }
        }

    }

    void even(function<void(int)> printNumber) {
        for (int i = 1; i <= ke; i++) {
            e.lock();
            printNumber(2*i);
            z.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= ko; i++) {
            o.lock();
            printNumber(2*i - 1);
            z.unlock();
        }
    }
};

int main(int argc, char ** argv) {

    // ZeroEvenOdd zeo(10);
    ZeroEvenOdd zeo(11);

    #pragma omp parallel for
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            zeo.zero(printNumber);
        }
        else if (i == 1) {
            zeo.odd(printNumber);
        }
        else {
            zeo.even(printNumber);
        }
    }

    cout << endl;

    return 0;
}