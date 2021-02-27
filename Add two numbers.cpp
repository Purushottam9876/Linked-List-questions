//Problem : https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Space Complexity O(max(m+n))
        int temp = (l1->val+l2->val)%10;
        ListNode *new_list = new ListNode(temp);
        ListNode *q = new_list;
        int c = (l1->val+l2->val)/10;
        l1=l1->next;
        l2=l2->next;
        while(l1!=NULL && l2!=NULL)
        {
            temp = (l1->val+l2->val+c)%10;
            q->next = new ListNode(temp);
            q=q->next;
            c = (l1->val+l2->val+c)/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            temp = (l1->val+c)%10;
            c = (l1->val+c)/10;
            q->next = new ListNode(temp);
            q=q->next;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            temp = (l2->val+c)%10;
            c = (l2->val+c)/10;
            q->next = new ListNode(temp);
            q=q->next;
            l2=l2->next;
        }
        if(c>0)
            q->next = new ListNode(c);
        return new_list;
        
        //Space Complexity O(1)
        ListNode*p = l1,*q = l2,*r,*s,*ret;
        int c=0;
        while(p!=NULL && q!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        if(q!=NULL)
        {
            r=l2;
            ret = l2;
            s=l1;
        }
        else
        {
            r=l1;
            ret = l1;
            s=l2;
        }
        int k;
        while(s!=NULL)
        {
            k = (r->val+s->val+c)%10;
            c = (r->val+s->val+c)/10;
            r->val = k;
            s=s->next;
            if(r->next==NULL && c>0)
            {
                r->next = new ListNode(c); 
                return ret;
            }
            else
                r=r->next;
        }
        while(r!=NULL)
        {
            k = (r->val+c)%10;
            c = (r->val+c)/10;
            r->val = k;
            if(r->next==NULL && c>0)
            {
               r->next = new ListNode(c); 
                break;
            }
            r=r->next;
        }
        return ret;
    }
};
