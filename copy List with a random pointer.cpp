/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return head;

        Node* temp = head;
        while(temp != NULL){
            Node* t = new Node(temp->val);
            t->next = temp->next;
            temp->next = t;
            temp = t->next;
        }
        temp = head;
        Node* ans = head->next;
        while(temp != NULL){
            // cout<< temp->random->val;
            Node* rnd = NULL;
            if(temp->random != NULL)
                rnd = temp->random->next;
            temp->next->random = rnd;
            Node* tp = temp->next;
            temp = tp->next;
            
            // if(tp->next!=NULL)
                // temp->next = temp->next->next;
            // if(tp->next != NULL)
            //     tp->next = tp->next->next;
        }
        temp = head;

        while(temp != NULL){
            Node* tp = temp->next;
            temp->next = tp->next;
            if(temp->next != NULL){
                tp->next = tp->next->next;
            }
            temp = temp->next;
        }

        return ans;
    }
};