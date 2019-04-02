#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class TreeNode {
public:
    int val;
    int height;
    int maxHeight;
    bool placeholder;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), height(0), maxHeight(0), placeholder(false), left(NULL), right(NULL) {}
    TreeNode(int x, int h) : val(x), height(h), maxHeight(0), placeholder(false), left(NULL), right(NULL) {}
    TreeNode(int x, int h, int mh) : val(x), height(h), maxHeight(mh), placeholder(false), left(NULL), right(NULL) {}
    TreeNode(bool ph, int h) : val(0), height(h), maxHeight(0), placeholder(ph), left(NULL), right(NULL) {}
};

template<typename T>
void printStack(const stack<T>& stk) {
    stack<T>cpy(stk);
    cout << "Top:: ";
    while(!cpy.empty()) {
        cout << cpy.top();
        cpy.pop();
        if (!cpy.empty()) cout << " -> ";
    }
    cout << " ::Bottom" << endl;
};

template<typename T>
void printVector(const vector<T>& vct, const string delim = " ", const string linebreak = "\n") {
    for(size_t i = 0; i < vct.size(); i++)
    {
        cout << vct[i] << delim;
    }
    cout << linebreak;
}

template<typename T>
vector<T> vectorFromArray(const T arr[], size_t asz) {
    return vector<T> (arr, arr+asz/sizeof(T));
}

//assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

void printList(ListNode* head) {
    if (!head) {
        printf("NULL head.\n");
        return;
    }

    while (head) {
        printf("%d", head->val);
        if (head -> next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

void printTree(TreeNode* root) {
    if (!root) {
        printf("Null Tree\n");
        return; 
    }
    // bfs
    queue<TreeNode*> q;
    q.push(root);
    int curH = root->height;
    int maxH = root->maxHeight;
    int pad = maxH - curH + 1;
    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        if (!cur->placeholder) {
            if (cur->height > curH) {
                curH = cur->height;
                pad = maxH - curH + 1;
                printf("\n");
            }
            for (int i = 0; i < pad; i++) {
                printf(" ");
            }
            printf("%d", cur->val);
            for (int i = 0; i < pad; i++) {
                printf(" ");
            }
            // Do not iterate leaf child
            if (cur->left || cur->right) {
                if (cur->left)
                    q.push(cur->left);
                else
                    q.push(new TreeNode(true, curH+1));

                if (cur->right)
                    q.push(cur->right);
                else
                    q.push(new TreeNode(true, curH+1));
            }
        }
        else {
            if (cur->height > curH) {
                curH = cur->height;
                pad = maxH - curH + 1;
                printf("\n");
            }
            for (int i = 0; i < pad; i++) {
                printf(" ");
            }
            printf("nul");
            for (int i = 0; i < pad; i++) {
                printf(" ");
            }
        }
    }
    printf("\n");
}
