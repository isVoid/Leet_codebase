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
//1Q
//4ms 100%
class MyStack {
public:

    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for(size_t i = 0; i < q.size()-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int f = q.front();
        q.pop();
        return f;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};


int main(int argc, char ** argv) {

    MyStack ms;
    ms.push(1);
    ms.push(2);
    cout << ms.pop() << endl;
    cout << ms.top() << endl;
    
    cout << ms.empty() << endl;
    ms.pop();
    cout << ms.empty() << endl;
    return 0;
}