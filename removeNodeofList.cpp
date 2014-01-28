#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            if (head == NULL)
                return NULL;
            ListNode** p = &head;
            int len = 0;
            while (*p) {
                len++;
                p = &((*p)->next);
            }
            int step = len-n;
            p = &head;
            for (int i=0;i < step;i++)
                p = &((*p)->next);
            delete *p;
            *p = (*p)->next;
            return head;
        }
};
