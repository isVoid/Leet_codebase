#include <iostream>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // Hash 6.33%, 28ms
    // 12MB, 100%
    // bool hasCycle(ListNode* head) {
    //     set<void*> l;

    //     while (head) {
    //         if (l.find(head) != l.end()) {
    //             return true;
    //         }
    //         l.insert(head);
    //         head = head->next;
    //     }

    //     return false;
    // }

    // 2 ptrs
    // 12ms 100%
    // 9.8MB, 100%
    bool hasCycle(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast && slow) {
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
            if (fast == slow && fast && slow) {
                return true;
            }
        }
        return false;
    }

};

int main() {

    // ListNode* p = new ListNode(1);
    // p->next = new ListNode(2);
    // p->next->next = new ListNode(3);
    // p->next->next->next = new ListNode(4);
    // p->next->next->next->next = p->next; // loop

    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = p; // loop

    // ListNode* p = new ListNode(1);

    Solution s;
    cout << s.hasCycle(p) << endl;

    return 0;
}

