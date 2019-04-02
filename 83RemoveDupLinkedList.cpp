#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Input: 1->1->2->3->3
// Output: 1->2->3

class Solution {
public:
    // 8ms, 98.5%
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* h = head;
        while (head != NULL) {
            ListNode* lh = head->next;
            while (lh != NULL && lh->val == head->val) {
                    lh = lh->next;
            }
            head->next = lh;
            head = head->next;
        }
        return h;
    }
};

int main() {
    ListNode* h = new ListNode(1);
    ListNode* p = h;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    
    for (ListNode* r = h; r!= NULL; r = r->next) {
        cout << r->val << " ";
    }
    cout << endl;

    Solution s;
    ListNode* r = s.deleteDuplicates(h);

    for (; r!= NULL; r = r->next) {
        cout << r->val << " ";
    }
    cout << endl;

    return 0;
}