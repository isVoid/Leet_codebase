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
class Solution {
public:
    //32ms 5.38%
    //12MB 9.24%
    // ListNode *detectCycle(ListNode *head) {
    //     set<void*> a;
    //     while (head != nullptr && a.count(head) == 0) {
    //         a.insert(head);
    //         head = head->next;
    //     }
    //     //nullptr if no cycle
    //     return head;
    // }

    //8ms 98.92%
    //9.6MB 92.67%
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }

        ListNode *s = head->next, *f = head->next->next;

        while (f && f->next && s != f) {
            s = s->next;
            f = f->next->next;
        }

        cout << s->val << endl;
        cout << f->val << endl;

        //Cycle not exists;
        if (!f || !f->next) {
            return nullptr;
        }

        s = head;
        while (s != f) {
            s = s->next;
            f = f->next;
        }

        return s;
    }
};

int main(int argc, char ** argv) {

    //3->7->4->5->6
    //   |________|
    ListNode* head = new ListNode(3);
    head->next = new ListNode(7);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = head->next;


    if (Solution().detectCycle(head) != nullptr) {
        cout << Solution().detectCycle(head)->val << endl;
    }
    else {
        cout << "No Cycle" << endl;
    }

    return 0;
}