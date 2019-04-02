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

    // //Set
    // //80ms, 17.15%
    // //20.1MB, 100.00%
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     set<ListNode*> s;

    //     while (headA) {
    //         s.insert(headA);
    //         headA = headA->next;
    //     }

    //     while (headB) {
    //         if (s.find(headB) != s.end()) {
    //             return headB;
    //         }
    //         headB = headB->next;
    //     }

    //     return NULL;
    // }

    //Two Ptr
    // 56ms 98.55%
    // 16.6MB, 100%
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        ListNode *AEnd = NULL, *BEnd = NULL;

        if (!headA && !headB)
            return NULL;

        while(1) {

            if (p1 && p2 && p1 == p2)
                return p1;

            if (p1 && !p1->next) {
                AEnd = p1;
            }
            if (p2 && !p2->next) {
                BEnd = p2;
            }
            if (AEnd && BEnd) {
                cout << AEnd << " " << BEnd << endl;
                if (AEnd != BEnd) {
                    return NULL;
                }
            }

            if (p1) 
                p1 = p1->next;
            else 
                p1 = headB;

            if (p2)
                p2 = p2->next;
            else 
                p2 = headA;

        }
    }
};

// int main() {
//     ListNode *A = NULL;
//     ListNode *B = new ListNode(5);

//     A = B;

//     cout << A->val << endl;

//     return 0;
// }

int main() {

    // ListNode *A = new ListNode(1);
    // A->next = new ListNode(2);
    // A->next->next = new ListNode(3);
    // A->next->next->next = new ListNode(4);
    // A->next->next->next->next = new ListNode(5);

    // ListNode *B = new ListNode(11);
    // B->next = new ListNode(22);
    // // B->next->next = A->next->next; //Intersect

    // ListNode *A = new ListNode(1);
    // ListNode *B = A;

    ListNode *A = NULL;
    ListNode *B = NULL;

    cout << "A: ";
    ListNode *AA = A;
    while (AA) {
        cout << AA->val << " ";
        AA = AA->next;
    }
    cout << endl;

    cout << "A: ";
    AA = A;
    while (AA) {
        cout << AA << " ";
        AA = AA->next;
    }
    cout << endl;

    cout << "B: ";
    ListNode *BB = B;
    while (BB) {
        cout << BB->val << " ";
        BB = BB->next;
    }
    cout << endl;


    cout << "B: ";
    BB = B;
    while (BB) {
        cout << BB << " ";
        BB = BB->next;
    }
    cout << endl << endl;

    Solution s;
    ListNode* r = s.getIntersectionNode(A, B);
    if (r)
        cout << r->val << endl;
    else
        cout << "NULL" << endl;

    return 0;
}