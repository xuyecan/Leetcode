#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *reverseKGroup(ListNode *head, int k) {
            ListNode *cur, *nxt, *nxt_seg;
            cur = head;
            ListNode *lst = NULL;
            if (head == NULL || k <= 1)
                return head;

            ListNode *cnt, *end;
            while (true) {
                int step = 0;
                cnt = cur;
                while (cnt && step++ < k) {
                    end = cnt;
                    cnt = cnt->next;
                }
                if (step < k)
                    break;
                head == cur && (head = end);
                lst && (lst->next = end);
                lst = NULL;
                nxt_seg = nxt = end->next;
                ListNode *tmp;
                for (int i=0;i < k-1;i++) {
                    lst == NULL && (lst = cur);
                    end->next = cur;
                    tmp = cur;
                    cur = cur->next;
                    tmp->next = nxt;
                    nxt = tmp;
                }
                cur = nxt_seg;
            }
            return head;
        }
};

int main()
{
    int a[10];
    for (int i=0;i < 10;i++) a[i] = i;
    ListNode *head = new ListNode(a[0]);
    ListNode *cur = head;
    for (int i=1;i < 10;i++){
        cur->next = new ListNode(a[i]);
        cur = cur->next;
    }
    ListNode *ret = (new Solution())->reverseKGroup(head, 21);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
}
