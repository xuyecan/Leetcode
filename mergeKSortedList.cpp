#include <iostream>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Pointer {
    ListNode *p;
    int belongTo;

    Pointer(ListNode *p, int bt) {
        this->p = p;
        this->belongTo = bt;
    }
    bool operator < (const Pointer &p) const {
        return this->p->val > p.p->val;
    }
    bool operator == (const Pointer &p) const {
        return this->p->val == p.p->val;
    }
};

class MyPQ {
    public:
        vector<Pointer> v;
        void push(Pointer p) {
            v.push_back(p);
            push_heap(v.begin(), v.end());
        }
        void pop() {
            pop_heap(v.begin(), v.end());
            v.pop_back();
        }
        Pointer top() {
            return v.front();
        }
        bool empty() {
            return v.empty();
        }
        bool size() {
            return v.size();
        }
        void print() {
            cout << "printf: " ;
            for (int i=0;i < v.size();i++)
                cout << v[i].p->val << " ";
            cout << endl;
        }
};

class Solution {
    public:
        ListNode *mergeKLists(vector<ListNode *> &lists) {
            MyPQ pq;
            for (int i=0;i < lists.size();i++) {
                ListNode *node = getNode(lists[i]);
                if (node)
                    pq.push(Pointer(node, i));
            }
            ListNode * head = NULL;
            ListNode **cur = &head;
            while (!pq.empty()) {
                Pointer pt = pq.top();
                pq.pop();
                *cur = pt.p;
                ListNode *node = getNode(lists[pt.belongTo]);
                if (node)
                    pq.push(Pointer(node, pt.belongTo));
                cur = &((*cur)->next);
            }
            return head;
        }

        ListNode* getNode(ListNode *&list) {
            if (list == NULL)
                return NULL;
            ListNode *p = list;
            list = list->next;
            return p;
        }
};

int main() {
    int a[5] = {2, 5, 12, 53, 234};
    int b[3] = {3, 4, 8};
    vector<ListNode* > v;
    ListNode *h1, *h2;
    h1 = new ListNode(a[0]);
    h2 = new ListNode(b[0]);
    ListNode *cur1 = h1, *cur2 = h2;
    for (int i=1;i < 5;i++){
        ListNode *p = new ListNode(a[i]);
        cur1->next = p;
        cur1 = cur1->next;
    }
    for (int i=1;i < 3;i++) {
        ListNode *p = new ListNode(b[i]);
        cur2->next = p;
        cur2 = cur2->next;
    }
    v.push_back(h1);
    v.push_back(h2);
    Solution so;
    ListNode *ret = so.mergeKLists(v);
    ListNode *h = ret;
    while (h) {
        cout << h->val << " ";
        h = h->next;
    }
    return 0;
}
