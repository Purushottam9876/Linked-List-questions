//Problem : https://leetcode.com/problems/linked-list-cycle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Recursive Solution
class Solution {
public:
    ListNode *a[10000];
    bool hasCycle(ListNode *head,int n=0) {
        if(head!=NULL)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i] == head)
                    return true;
            }
            a[n] = head;
            n=n+1;
            return hasCycle(head->next,n);
        }
        return false;
    }
};


//Iterative and two ointer approach
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        ListNode *fast=head->next,*slow=head;
        while(fast!=NULL && fast!=slow)
        {
            if(fast->next!=NULL)
                fast=fast->next->next;
            else
                fast= fast->next;
            slow = slow->next;
        }
        if(fast==slow)
            return true;
        else
            return false;
    }
};
