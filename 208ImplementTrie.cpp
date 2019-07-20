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

struct TrieNode {
    TrieNode* childs[26];
    bool isLeaf;
    TrieNode() {
        memset(childs, 0, sizeof(TrieNode*) * 26);
        isLeaf = false;
    }
};

// Runtime: 68 ms, faster than 90.59%
// Memory Usage: 44.9 MB, less than 39.61%
class Trie {
public:

    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        int i = 0;
        while (i < word.size() && (cur->childs)[word[i] - 'a'] != nullptr) {
            cur = (cur->childs)[word[i] - 'a'];
            i++;
        }

        while (i < word.size()) {
            (cur->childs)[word[i] - 'a'] = new TrieNode();
            cur = (cur->childs)[word[i] - 'a'];
            i++;
        }

        cur->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        int i = 0;

        while (i < word.size() && (cur->childs)[word[i] - 'a'] != nullptr) {
            cur = (cur->childs)[word[i] - 'a'];
            i++;
        }

        return i == word.size() && cur->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        int i = 0;

        while (i < prefix.size() && (cur->childs)[prefix[i] - 'a'] != nullptr) {
            cur = (cur->childs)[prefix[i] - 'a'];
            i++;
        }

        return i == prefix.size();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char ** argv) {

    Trie trie = Trie();
    trie.insert("apple");
    cout << trie.search("app") << endl;
    cout << trie.search("apple") << endl;
    trie.insert("app");
    cout << trie.search("app") << endl;

    return 0;
}