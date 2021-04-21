#include<iostream>
#include<forward_list>
using namespace std;



 struct ListNode {
     int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
 
ListNode* removeDuplicateNodes(ListNode* head) {
    if (head->next == NULL || head->next->next == NULL) return head;
    ListNode* p = head->next->next, * last = head->next;
    while (p)
    {

        bool same = false;
        ListNode* q = head->next;
        while (q != last->next)
        {
            if (p->val == q->val)
            {
                last->next = p->next;
                same = true;
                //delete p;
                break;
            }
            q = q->next;
        }
        ;
        if (!same)
        {
            last = last->next;
            p = last->next;
        }
        else
            p = p->next;
    }
    return head;
}

int main()
{

}