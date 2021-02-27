//Problem : https://leetcode.com/problems/remove-linked-list-elements/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL)
        {
            if(head->val==val)
                head=head->next;
            else
                break;
        }
        if(head==NULL)
             return NULL;
        ListNode *p = head->next,*prev=head;
        while(p!=NULL)
        {
            if(p->val==val)
                prev->next = p->next;
            else
                prev = prev->next;
            p=p->next;
        }
        return head;
    }
};
