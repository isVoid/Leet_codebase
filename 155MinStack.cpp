#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Naive
// 40ms, 92.4%
// 17.1MB 100%
class MinStack {
public:

    /** initialize your data structure here. */
    MinStack() {
        stack_top = NULL;
        min = INT_MAX;
    }
    
    void push(int x) {
        ListNode* nTop = new ListNode(x);
        nTop->next = stack_top;
        stack_top = nTop;
        if (x < min) {
            min = x;
        }
    }
    
    void pop() {
        ListNode* tmp = stack_top;
        stack_top = stack_top->next;
        delete tmp;
        findMin();
    }
    
    int top() {
        return stack_top->val;
    }
    
    // O(1) time
    int getMin() {
        return min;
    }

private:
    ListNode* stack_top;
    int min;

    void findMin() {
        min = INT_MAX;
        ListNode* head = stack_top;
        while(head) {
            if (head->val < min) {
                min = head->val;
            }
            head = head->next;
        }
    }
};

int main() {

    // MinStack obj = MinStack();
    // obj.push(0);
    // obj.push(2);
    // obj.push(1);
    // obj.push(-1);

    // for (auto i : obj.v) {
    //     cout << i->val << " ";
    // }
    // cout << endl;

    // // -1 -> 1 -> 2 -> 0

    // int t = obj.top();  //-1
    // cout << "top: " << t << endl;

    // int mn = obj.getMin();  //-1
    // cout << "min: " << mn << endl;

    // obj.pop();
    // t = obj.top(); //1
    // cout << "top: " << t << endl;

    // mn = obj.getMin(); //0
    // cout << "min: " << mn << endl;

    MinStack obj = MinStack();
    obj.push(-2);
    obj.push(0);
    obj.push(-3);

    int mn = obj.getMin();  //-3
    cout << "min: " << mn << endl;

    obj.pop();

    int t = obj.top(); //0
    cout << "top: " << t << endl;

    mn = obj.getMin(); //-2
    cout << "min: " << mn << endl;

    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */