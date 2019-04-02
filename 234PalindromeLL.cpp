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
class Solution {
public:
    //RTE??
    // bool isPalindrome(ListNode* head) {
    //     if (!head) return true;
    //     if (!head->next) return true;

    //     ListNode *p = head;
    //     ListNode *tail = NULL;
        
    //     //First pass: count length
    //     int length = 0;
    //     while(p) {
    //         if (!p->next) {
    //             tail = p;
    //         }
    //         p = p->next;
    //         length++;
    //     }
    //     // printf("Length: %d\n", length);
    //     if (length == 2) {
    //         return head->val == head->next->val;
    //     }

    //     //Second pass: revert direction of
    //     //the second half of the list
    //     ListNode *pv = head;
    //     p = pv->next;
    //     for (int i = 0; i < length / 2; i++) {
    //         pv = p;
    //         p = p->next;
    //     }
    //     // printf("Reaching second half. p->val: %d, pv->val: %d\n", p->val, pv->val);

    //     int secondHalfLength = length / 2;
    //     if (length % 2 == 0) secondHalfLength--;
    //     for (int i = 0; i < secondHalfLength; i++) {
    //         ListNode *next = p->next;
    //         p->next = pv;
    //         pv = p;
    //         p = next;
    //     }

    //     //Third pass: check palindrome
    //     for (int i = 0; i < length / 2; i++) {
    //         // printf("Head: %d, Tail: %d\n", head->val, tail->val);
    //         if (head->val != tail->val) return false;
    //         head = head->next;
    //         tail = tail->next;
    //     }

    //     return true;

    // }

    //24ms, 98.57%
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *mid = head, *fast = head, *prev = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode *next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }
        if (fast) mid = mid->next;

        while(prev && mid) {
            if (prev->val != mid->val) return false;

            prev = prev->next;
            mid = mid->next;
        }
        return true;
    }
};

int main(int argc, char ** argv) {

    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(5);
    l->next->next->next = new ListNode(2);
    l->next->next->next->next = new ListNode(1);

    // ListNode *l = NULL;

    printList(l);
    Solution s;

    cout << s.isPalindrome(l) << endl;

    return 0;
}