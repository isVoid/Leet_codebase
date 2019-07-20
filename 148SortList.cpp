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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* mergeSort(ListNode *head) {
        if (!head) return nullptr;

        ListNode *tail = head;
        while (tail->next) {
            tail = tail->next;
        }

        ListNode *sorted = mergeHelper(head, tail);

        return sorted;
    }

    // Allocation
    // ListNode* mergeHelper(ListNode *head, ListNode *tail) {

    //     if (!head) {
    //         return nullptr;
    //     }
    //     //1 num
    //     else if (head == tail) {
    //         ListNode *ans = new ListNode(head->val);
    //         return ans;
    //     }

    //     ListNode *fast = head, *slow = head;
    //     while ( fast && fast->next && fast != tail && fast->next != tail) {
    //         fast = fast->next->next;
    //         slow = slow->next;
    //     }

    //     ListNode *hl = mergeHelper(head, slow);
    //     ListNode *hr = mergeHelper(slow->next, tail);

    //     ListNode *ans = nullptr, *h;
    //     while (hl || hr) {
    //         ListNode *next = nullptr;
    //         if (hl && hr) {
    //             if (hl->val < hr->val) {
    //                 next = new ListNode(hl->val);
    //                 hl = hl->next;
    //             }
    //             else {
    //                 next = new ListNode(hr->val);
    //                 hr = hr->next;
    //             }
    //         }
    //         else if (hl) {
    //             next = new ListNode(hl->val);
    //             hl = hl->next;
    //         }
    //         else {
    //             next = new ListNode(hr->val);
    //             hr = hr->next;
    //         }

    //         if (!ans) {
    //             ans = next;
    //             h = ans;
    //         }
    //         else {
    //             h->next = next;
    //             h = h->next;
    //         }
    //     }

    //     return ans;

    // }

    // In place
    // Runtime: 36 ms, faster than 99.79%
    // Memory Usage: 11.8 MB, less than 67.06%
    ListNode* mergeHelper(ListNode *head, ListNode *tail) {

        if (!head) {
            return nullptr;
        }
        //1 num
        else if (head == tail) {
            // ListNode *ans = new ListNode(head->val);
            head -> next = nullptr;
            return head;
        }

        ListNode *fast = head, *slow = head;
        while ( fast && fast->next && fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }

        //Next recursion may break the list
        ListNode *slow_next = slow->next;
        ListNode *hl = mergeHelper(head, slow);
        ListNode *hr = mergeHelper(slow_next, tail);

        ListNode *tmp = nullptr, *h = nullptr, *ans = nullptr;
        while (hl || hr) {
            if (hl && hr) {
                if (hl->val < hr->val) {
                    if (!h) {
                        h = hl;
                    }
                    else {
                        h->next = hl;
                        h = h->next;
                    }
                    hl = hl->next;
                }
                else {
                    if (!h) {
                        h = hr;
                    }
                    else {
                        h->next = hr;
                        h = h->next;
                    }
                    hr = hr->next;
                }
            }
            else if (hl) {
                h->next = hl;
                break;
            }
            else {
                h->next = hr;
                break;
            }

            if (!ans) {
                ans = h;
            }

        }

        return ans;

    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};

int main(int argc, char ** argv) {

    // ListNode *h = new ListNode(2);
    // h->next = new ListNode(4);
    // h->next->next = new ListNode(1);
    // h->next->next->next = new ListNode(3);

    ListNode *h = new ListNode(4);
    h->next = new ListNode(2);
    h->next->next = new ListNode(1);
    h->next->next->next = new ListNode(3);

    // ListNode *h = new ListNode(-1);
    // h->next = new ListNode(5);
    // h->next->next = new ListNode(3);
    // h->next->next->next = new ListNode(4);
    // h->next->next->next->next = new ListNode(0);
    // h->next->next->next->next->next = new ListNode(4);


    // ListNode *h = nullptr;

    // ListNode *h = new ListNode(1);

    cout << "Before Sort" << endl;
    printList(h);

    ListNode *sh = Solution().sortList(h);

    cout << "After Sort" << endl;
    printList(sh);

    return 0;
}