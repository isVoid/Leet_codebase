#include <iostream>
#include <vector>
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

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

int main(int argc, char ** argv) {

    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    // 1 <- 2 <- 3
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    q.push(4);

    // 3 <- 4
    cout << q.pop() << endl;

    cout << q.empty() << endl;
 
    return 0;
}