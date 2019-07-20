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

void releaseHydrogen() {cout << "H";};
void releaseOxygen() {cout << "O";};

class PV {
private:
    mutex m;
    condition_variable cv;
public:
    size_t s;
public:
    PV(size_t _s) : s(_s) {}

    void P() {
        unique_lock<mutex> lock(m);
        while (s == 0) {
            cv.wait(lock);
        }
        s--;
    }
    void V() {
        s++;
        cv.notify_all();
    }
    void reset(size_t _s) {
        s = _s;
        cv.notify_all();
    }

};

struct ListNode;
struct TreeNode;
class H2O {
public:

    PV *H, *O;
    int hcount = 0;
    H2O() {
        H = new PV(2);
        O = new PV(0);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        O->P();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        cout << "H" << " " << O->s << endl;
        // releaseHydrogen();
        H->V();
    }

    void oxygen(function<void()> releaseOxygen) {
        H->P();
        H->P();
        cout << "O " << H->s << endl;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        // releaseOxygen();
        O->V();
        O->V();
    }
};
int main(int argc, char ** argv) {

    // string in = "HHHHOO";
    string in = "OOOOHOOOOOHOHHOHHOHHOOHHOOHHOOOOHHHHHHHHOHHHHOOHHOHOOOHOHHOHOOOOHOOOOOHOOOOOHHHHOHHOOHOHOOHOHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH";
    // int h = 0, o = 0;
    // for (int i = 0; i < in.size(); i++) {
    //     if (in[i] == 'O') {
    //         o++;
    //     }
    //     if (in[i] == 'H') {
    //         h++;
    //     }
    // }
    // cout << o << " " << h << endl;
    // return -1;
    H2O h2o;
    #pragma omp parallel for
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == 'H') {
            h2o.hydrogen(releaseHydrogen);
        }
        else {
            h2o.oxygen(releaseOxygen);
        }
    }
    cout << endl;

    return 0;
}