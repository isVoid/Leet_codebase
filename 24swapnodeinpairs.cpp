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
    //100%
    //100%
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *p0 = nullptr, *p1 = head, *p2 = head->next, *p3 = head->next->next;
        ListNode *pH = p2;

        while (p2) {
            // cout << p0 << " " << p1 << " " << p2 << " " << p3 << endl;

            p1->next = p3;
            p2->next = p1;
            if (p0) p0->next = p2;
            // return pH;

            // cout << "here" << endl;

            p0 = p1;
            p1 = p3;
            p2 = p1 ? p1->next : nullptr;
            p3 = p2 ? p2->next : nullptr;

        }
        return pH;
    }
};

int main(int argc, char ** argv) {

    // vector<int> v({1, 2, 3 ,4});
    // vector<int> v({1, 2, 3 ,4, 5});
    vector<int> v({1});
    // vector<int> v;

    ListNode *h = makeList(v);

    printList(h, true);

    ListNode *nh = Solution().swapPairs(h);

    printList(nh, true);

    return 0;
}