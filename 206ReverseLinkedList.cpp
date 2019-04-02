#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include "dbg.hpp"
using namespace std;

struct ListNode;
class Solution {
public:

    ListNode* reverse(ListNode *cur, ListNode *pre, bool start = true) {
        ListNode *next = cur->next;
        cur->next = pre;

        if (start) {
            pre->next = NULL;
        }

        if (!next) {
            return cur;
        }
        return reverse(next, cur, false);
    }

    //Recursive
    //8ms, 100%
    //9.2MB, 37.99%
    ListNode* reverseList(ListNode* head) {

        if (!head || !head->next) {
            return head;
        }

        ListNode *nHead = reverse(head->next, head);

        return nHead;
    }
};

int main(int argc, char ** argv) {

    //1->2->3->4->5->NULL
    // ListNode *l = new ListNode(1);
    // l->next = new ListNode(2);
    // l->next->next = new ListNode(3);
    // l->next->next->next = new ListNode(4);
    // l->next->next->next->next = new ListNode(5);

    // 3->6->9
    // ListNode *l = new ListNode(3);
    // l->next = new ListNode(6);
    // l->next->next = new ListNode(9);
    
    // 1
    // ListNode *l = new ListNode(1);

    // 1->2
    // ListNode *l = new ListNode(1);
    // l->next = new ListNode(2);

    //NULL
    ListNode *l = NULL;

    Solution s;
    ListNode *r = s.reverseList(l);

    printList(r);

    return 0;
}