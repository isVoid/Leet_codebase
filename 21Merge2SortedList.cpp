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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* mhead = NULL;
        ListNode* m = NULL;

        while (l1 != NULL && l2 != NULL) {
            int curN;
            if (l1->val <= l2->val) {
                curN = l1->val;
                l1 = l1->next;
            }
            else {
                curN = l2->val;
                l2 = l2->next;
            }

            if (mhead == NULL) {
                m = new ListNode(curN);
                mhead = m;
            }
            else {
                m->next = new ListNode(curN);
                m = m->next;
            }

        }

        while (l1 == NULL && l2 != NULL) {
            if (mhead == NULL) {
                m = new ListNode(l2->val);
                mhead = m;
            }
            else {
                m->next = new ListNode(l2->val);
                m = m->next;
            }
            l2 = l2->next;
        }

        while (l1 != NULL && l2 == NULL) {
            if (mhead == NULL) {
                m = new ListNode(l1->val);
                mhead = m;
            }
            else {
                m->next = new ListNode(l1->val);
                m = m->next;
            }
            l1 = l1->next;
        }

        return mhead;
        
    }
};

int main() {

    // ListNode* l1 = new ListNode(1);
    ListNode* l1 = NULL;
    ListNode* l2 = new ListNode(1);
    ListNode* pl1 = l1;
    ListNode* pl2 = l2;
    // NULL
    // pl1->next = new ListNode(2); pl1 = pl1->next;
    // pl1->next = new ListNode(4);

    // 1->3->4
    pl2->next = new ListNode(3); pl2 = pl2->next;
    pl2->next = new ListNode(4);

    pl1 = l1;
    cout << "l1: ";
    while (pl1 != NULL) {
        cout << pl1->val << " ";
        pl1 = pl1->next;
    }
    cout << endl;

    pl2 = l2;
    cout << "l2: ";
    while (pl2 != NULL) {
        cout << pl2->val << " ";
        pl2 = pl2->next;
    }
    cout << endl;

    Solution s;
    ListNode* merged = s.mergeTwoLists(l1, l2);
    cout << merged << endl;
    ListNode* rdr = merged;

    cout << "merged: ";
    while (rdr != NULL) {
        cout << rdr->val << " ";
        rdr = rdr->next;
    }
    cout << endl;

    return 0;
}