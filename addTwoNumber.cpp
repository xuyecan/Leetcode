#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        string add(string s1, string s2) {
            while (s1.length() < s2.length())
                s1 = char(0) + s1;
            while (s1.length() > s2.length())
                s2 = char(0) + s2;
            s1 = char(0) + s1;
            s2 = char(0) + s2;
            for (int i=s1.length()-1;i >= 0;i--) {
                s1[i] += s2[i];
                if (s1[i] > 9) {
                    s1[i] -= 10;
                    s1[i-1]++;
                }
            }
            if (s1[0] == 0)
                s1.erase(0, 1);
            if (s1.length() == 0)
                s1 = string(char(0));
            return s1;
        }
        string getNumFromList(ListNode *list) {
            string ret;
            while (list) {
                ret = (char)list->val + ret;
                list = list->next;
            }
            return ret;
        }
        ListNode* buildListFromNum(string n) {
            ListNode * head = new ListNode(n[n.length()-1]);
            ListNode * cur = head;
            for (int i=n.length()-2;i >= 0;i--) {
                cur->next = new ListNode(n[i]);
                cur = cur->next;
            }
            return head;
        }
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            return buildListFromNum(add(getNumFromList(l1), getNumFromList(l2)));
        }
};

int main()
{
    return 0;
}
