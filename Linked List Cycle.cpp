//Problem : https://leetcode.com/problems/linked-list-cycle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
