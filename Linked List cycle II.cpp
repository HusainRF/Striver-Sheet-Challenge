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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return NULL;

        ListNode * slow = head->next;
        ListNode * fast = head->next->next;
        int f = 0;
        while(fast != NULL && fast->next!=NULL){
            if(fast == slow)
            {
                f = 1;
                break;
            }
            fast = fast->next->next;
            slow= slow->next;
        }   
        if(!f)
            return NULL;

        slow = head;
        while(fast != slow){
            slow = slow->next;
            fast= fast->next;
        }
        return slow;

    }
};