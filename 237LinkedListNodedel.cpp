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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main(int argc, char ** argv) {

    ListNode *l = new ListNode(4);
    l->next = new ListNode(5);
    l->next->next = new ListNode(1);
    l->next->next->next = new ListNode(9);

    Solution s;

    printList(l);

    s.deleteNode(l->next);

    printList(l);

    return 0;
}