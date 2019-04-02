#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include "dbg.hpp"
using namespace std;

struct ListNode; // Defined in deb.hpp
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* first = head;
        ListNode* prev = NULL;
        while (head) {
            if (head->val == val) {
                ListNode* next = head->next;
                if (prev) {
                    prev->next = next;
                }
                if (head == first) {
                    first = next;
                }
                delete head;
                head = next;
            }
            else {
                prev = head;
                head = head->next;
            }
        }
        return first;
    }
};

int main(int argc, char ** argv) {

    ListNode* a = new ListNode(1);
    // a->next = new ListNode(2);
    // a->next->next = new ListNode(6);
    // a->next->next->next = new ListNode(7);
    // a->next->next->next->next = new ListNode(6);

    cout << "Before" << endl;
    printList(a);

    Solution s;
    ListNode* r = s.removeElements(a, 1);

    cout << "After" << endl;
    printList(a);

    return 0;
}