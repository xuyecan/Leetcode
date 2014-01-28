#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *swapPairs(ListNode *head) {
            ListNode *cur, *nxt, *occ;
            cur = head;
            ListNode *lst = NULL;
            if (head == NULL || head->next == NULL)
                return head;

            head = head->next;
            while (cur && cur->next) {
                lst && (lst->next = cur->next);
                nxt = cur->next->next;
                cur->next->next = cur;
                cur->next = nxt;
                lst = cur;
                cur = cur->next;
            }
            return head;
        }
};
