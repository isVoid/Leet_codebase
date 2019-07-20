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
// #include "dbg.hpp"
using namespace std;

// struct ListNode;
// struct TreeNode;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    // Runtime: 32 ms, faster than 83.48%
    // Memory Usage: 22.2 MB, less than 44.20%
    Node* copyRandomList(Node* head) {
        Node *old = head, *res = nullptr, *nHead = nullptr;
        unordered_map< Node*, vector<Node*> > dict;
        unordered_map<Node*, Node*> past;
        while (old) {
            Node *node = new Node(old->val, nullptr, nullptr);
            past.insert({old, node});

            //Being pointed to
            if (dict.find(old) != dict.end()) {
                for (Node* from : dict[old]) {
                    from->random = node;
                }
                // Node *from = dict[old];
            }

            //Self loop
            if (old->random == old) {
                node->random = node;
            }
            //Points to future, save
            else if (past.find(old->random) == past.end()) {
                // dict.insert({old->random, node});
                //new item
                if (dict.find(old->random) == dict.end()) {
                    dict[old->random] = {node};
                }
                else {
                    dict[old->random].emplace_back(node);
                }
            }
            //Points to past
            else {
                node->random = past[old->random];
            }

            //Advance
            if (nHead != nullptr) {
                nHead->next = node;
                nHead = node;
            }
            else {
                nHead = node;
                res = nHead;
            }
            old = old->next;
        }
        return res;
    }
};

int main(int argc, char ** argv) {

    // Node *h = new Node(1, nullptr, nullptr);
    // h->next = new Node(2, nullptr, nullptr);
    // h->next->next = new Node(3, nullptr, nullptr);
    // h->next->next->next = new Node(4, nullptr, nullptr);

    // h->random = h->next->next;
    // h->next->random = h->next;
    // h->next->next->random = h;
    // h->next->next->next->random = h->next->next;


    // //1-2-3-4
    // //1~>3
    // //2~>2
    // //3~>1
    // //4~>3

    // Node *h = new Node(1, nullptr, nullptr);

    // h->random = h;
    //1
    //1~>1

    Node *h = new Node(1, nullptr, nullptr);
    h->next = new Node(2, nullptr, nullptr);
    h->next->next = new Node(3, nullptr, nullptr);
    h->next->next->next = new Node(4, nullptr, nullptr);

    h->random = h->next->next;
    h->next->random = h->next->next;

    //1-2-3-4
    //1~>3
    //2~>3

    Node* deepcopy = Solution().copyRandomList(h);

    cout << "Finished deepcopy!" << endl;

    while (deepcopy != nullptr) {
        if (deepcopy->random)
            cout << deepcopy->val << " ~> " << deepcopy->random->val << endl;
        else
            cout << deepcopy->val << " ~> nullptr" << endl;
        cout << " | " << endl;
        deepcopy = deepcopy->next;
    }

    return 0;
}