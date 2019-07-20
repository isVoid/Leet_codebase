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

struct ListNode;
struct TreeNode;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node() {}

    Node(int _key, int _val, Node* _prev, Node* _next) {
        key = _key;
        val = _val;
        prev = _prev;
        next = _next;
    }
};

// Runtime: 108 ms, faster than 86.35%
// Memory Usage: 37.8 MB, less than 90.35%
class LRUCache {
public:

    unordered_map<int, Node*> cache;
    Node *head, *tail;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    void moveToHead(Node *&head, Node *&tail, Node *&target) {
        //If not already at top
        if (target != head) {
            //If at tail, update tail
            if (target == tail) {
                tail = target->prev;
            }
            //Remove from current list
            if (target->prev)
                target->prev->next = target->next;
            if (target->next)
                target->next->prev = target->prev;
            
            //Insert to head
            head->prev = target;
            target->next = head;
            head = target;
        }
    }

    int get(int key) {
        if (cache.count(key) > 0) {
            Node *target = cache.at(key);
            moveToHead(head, tail, target);
            return target->val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {

        if (capacity > 0) {
            //Does not exist
            if (cache.count(key) == 0) {
                //Cache is full
                if (capacity == cache.size()) {
                    //Remove LRU item from cache
                    int keyToRemove = tail->key;
                    cache.erase(keyToRemove);
                    
                    //Remove LRU item from list
                    Node *tmp = tail;
                    if (head == tail) {
                        head = nullptr;
                        tail = nullptr;
                    }
                    else {
                        tail = tail->prev;
                        if (tail)
                            tail->next = nullptr;
                    }
                    delete tmp;
                }
                
                //Insert new item to head of list
                Node *item = new Node(key, value, nullptr, nullptr);
                if (head) {
                    head->prev = item;
                    item->next = head;
                    head = item;
                }
                //The first item in list
                else {
                    head = item;
                    tail = item;
                }
                cache.insert(make_pair(key, item));
            }
            //exists
            else {
                Node *target = cache[key];
                target->val = value;
                moveToHead(head, tail, target);
            }
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(int argc, char ** argv) {

    LRUCache *c = new LRUCache(2);

    c->put(1, 1);
    c->put(2, 2);
    cout << c->get(1) << endl;
    c->put(3, 3);
    cout << c->get(2) << endl; 
    c->put(4, 4);
    cout << c->get(1) << endl;
    cout << c->get(3) << endl;
    cout << c->get(4) << endl;

    // LRUCache *c = new LRUCache(1);

    // c->put(2, 1);
    // cout << c->get(2) << endl;
    // c->put(3, 2);
    // cout << c->get(2) << endl; 
    // cout << c->get(3) << endl;

    // LRUCache *c = new LRUCache(2);

    // c->put(2, 1);
    // c->put(2, 2);
    // cout << c->get(2) << endl;
    // c->put(1, 1);
    // c->put(4, 1);
    // cout << c->get(2) << endl; 



    return 0;
}