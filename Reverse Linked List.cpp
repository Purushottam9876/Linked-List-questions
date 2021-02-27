//Problem : https://www.interviewbit.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* A) {
        if(A==NULL)
            return NULL;
        ListNode *prev=A, *curr=A->next , *head=A;
        while(curr!=NULL)
        {
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            curr = prev->next;
        }
        return head;   
    }
};
