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
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (idx.find(val) == idx.end()) {
            idx.insert({val, store.size()});
            store.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (idx.find(val) != idx.end()) {
            int i = idx[val];
            if (store.size() > 1) {
                idx[store[store.size()-1]] = i;
                swap(store[i], store[store.size()-1]);
            }
            idx.erase(val);
            store.pop_back();
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        srand(time(NULL));
        // printVector(store);
        return store[rand() % store.size()];
    }
private:
    unordered_map <int, int> idx;
    vector<int> store;
};

int main(int argc, char ** argv) {

    RandomizedSet rs;
    // cout << rs.insert(1) << endl;
    // cout << rs.insert(2) << endl;
    // cout << rs.insert(2) << endl;

    // cout << rs.remove(1) << endl;
    // cout << rs.remove(1) << endl;

    // cout << rs.insert(3) << endl;
    // cout << rs.insert(4) << endl;
    // cout << rs.getRandom() << endl;

    // cout << rs.insert(0) << endl;
    // cout << rs.insert(1) << endl;
    // cout << rs.remove(0) << endl;
    // cout << rs.insert(2) << endl;
    // cout << rs.remove(1) << endl;
    // cout << rs.getRandom() << endl;
    
    cout << rs.remove(0) << endl;
    cout << rs.remove(0) << endl;
    cout << rs.insert(0) << endl;
    cout << rs.getRandom() << endl;
    cout << rs.remove(0) << endl;
    cout << rs.insert(0) << endl;
    
    
    return 0;
}