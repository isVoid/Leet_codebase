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

void printFoo() {
    cout << "Foo";
}

void printBar() {
    cout << "Bar";
}

struct ListNode;
struct TreeNode;
class FooBar {
private:
    int n;
    // mutex f, b;
    bool turn = false;

public:
    FooBar(int n) {
        this->n = n;
        // b.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            // f.lock();
            while (turn);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            // b.unlock();
            turn = !turn;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            // b.lock();
            while (!turn);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            // f.unlock();
            turn = !turn;
        }
    }
};
int main(int argc, char ** argv) {

    FooBar fb(10);

    #pragma omp parallel for
    for (int i = 1; i >= 0; i--) {
        if (i == 0) {
            fb.foo(printFoo);
        }
        else {
            fb.bar(printBar);
        }
    }

    cout << endl;

    return 0;
}