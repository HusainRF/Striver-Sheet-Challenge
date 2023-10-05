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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL )
            return head;
        int n = 0 ;
        ListNode* t = head;
        ListNode* last = NULL;
        while(t != NULL){
            last = t;
            t= t->next;
            n++;
        }
        if(k%n == 0)
            return head;

        last->next = head;

        int z = n -k % n ;
        ListNode* curr =head , *prev =NULL;
        while(z){
            prev = curr;
            curr= curr->next;
            z--;
        }
        prev->next = NULL;
        return curr;
    }
};