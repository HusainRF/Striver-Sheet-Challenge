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
    ListNode* rev(ListNode* head){
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = head->next;

        while(curr != NULL){
            curr->next = prev;
            prev = curr;
            head = curr;
            curr = nxt;
            if(curr != NULL)
                nxt = curr->next;
        }
        return head;
    }
    bool isPalindrome(ListNode* head) {
        // int cnt0;
        ListNode* slow = head , *fast = head;
        while(fast->next != NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast= fast->next->next;
        }

        slow->next = rev(slow->next);
        slow = slow->next;


        ListNode* t = head;
        // while(t!= NULL){ 
        //     cout<< t->val<<" ";
        //     t = t->next;
        // }

        t = head;

        while(slow != NULL){
            if(t->val != slow->val)
                return 0;
            t = t->next;
            slow = slow->next;
        }
        return 1;

    }
};