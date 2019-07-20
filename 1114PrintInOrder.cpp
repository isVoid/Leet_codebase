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
class Foo {
public:
    void acquire(bool &mutex) {
        while (mutex) {
            //busy wait
        }
        mutex = true;
    }

    void release(bool &mutex) {
        mutex = false;
    }
    bool mutex1, mutex2;

    Foo() {
        mutex1 = true;
        mutex2 = true;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        release(mutex1);
    }

    void second(function<void()> printSecond) {
        
        acquire(mutex1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        release(mutex2);
    }

    void third(function<void()> printThird) {
        acquire(mutex2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        release(mutex2);
    }
};

int main(int argc, char ** argv) {

    return 0;
}