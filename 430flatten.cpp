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
struct Node;

class Solution {
public:

//80.82% 104ms
//31.1MB 36.00%
  Node *helper(Node *head, Node *parentNext)
  {
      Node *end;
      while (head)
      {

          if (!head->next && !head->child)
          {
              end = head;
          }

          if (head->child)
          {
            Node* next = head->next;
              head->next = head->child;
              head->child->prev = head;
              head->child = nullptr;

            Node *childend;
            if (next) {
                childend = helper(head->next, next);
                childend->next = next;
                next->prev = childend;
            }
            else {
                //override
                end = helper(head->next, parentNext);
            }
              
          }

          head = head->next;
      }

      return end;
    }

    Node* flatten(Node* head) {

        if (head == nullptr) return head;

        helper(head, nullptr);

        return head;
    }
};

int main(int argc, char ** argv) {

    //Test Case 1
    // vector<int> v({1, 2, 3, 4, 5, 6});
    // vector<int> v2({7, 8, 9, 10});
    // vector<int> v3({11, 12});
    // vector<int> v4({13, 14});

    // Node* h = makeDoublyLinkedList(v);
    // Node* h2 = makeDoublyLinkedList(v2);
    // Node* h3 = makeDoublyLinkedList(v3);
    // Node* h4 = makeDoublyLinkedList(v4);

    // insertChildListAt(2, h, h2);
    // insertChildListAt(1, h2, h3);
    // insertChildListAt(3, h2, h4);

    ////Test Case 2
    // vector<int> v({1, 2, 3});
    // vector<int> v2({4, 5});

    // Node* h = makeDoublyLinkedList(v);
    // Node* h2 = makeDoublyLinkedList(v2);

    // insertChildListAt(2, h, h2);

    //Test Case 3
    // vector<int> v({1, 2});
    // vector<int> v2({3, 4});
    // vector<int> v3({5});

    // Node* h = makeDoublyLinkedList(v);
    // Node* h2 = makeDoublyLinkedList(v2);
    // Node* h3 = makeDoublyLinkedList(v3);

    // insertChildListAt(0, h, h2);
    // insertChildListAt(1, h2, h3);

    // //Test Case 4
    // vector<int> v({1});
    // vector<int> v2({3});
    // vector<int> v3({5});

    // Node* h = makeDoublyLinkedList(v);
    // Node* h2 = makeDoublyLinkedList(v2);
    // Node* h3 = makeDoublyLinkedList(v3);

    // insertChildListAt(0, h, h2);
    // insertChildListAt(0, h2, h3);

    //Test Case 5
    // vector<int> v({1});
    // Node* h = makeDoublyLinkedList(v);

    //Test Case 6
    Node *h = nullptr;

    printListWithChild(h, false);

    cout << "Flatten" << endl;
    Node* fh = Solution().flatten(h);

    printDListTwoWay(fh, false);

    return 0;
}