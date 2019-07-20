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
    //8ms 83.12%
    //8.5MB 100%
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;

        ListNode* f = head, *s, *t;
        int i = 0;
        while (f != nullptr && i < n) {
            f = f->next;
            i++;
        }
        //list length less than N
        if (i != n) {
            return head;
        }

        s = head;
        t = nullptr;
        while (f != nullptr) {
            f = f->next;
            t = s;
            s = s->next;
        }

        if (t != nullptr) {
            t->next = s->next;
            delete s;
        }
        else {
            head = head->next;
            delete s;
        }

        return head;
    }
};

int main(int argc, char ** argv) {

    vector<int> v = {5, 4, 3, 2, 1};
    ListNode* h = makeList(v);
    // ListNode* h = nullptr;

    printList(h);

    ListNode* r = Solution().removeNthFromEnd(h, 8);

    printList(r);

    return 0;
}