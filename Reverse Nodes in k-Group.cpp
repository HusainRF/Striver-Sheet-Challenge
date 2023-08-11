// LEETCODE Solution:
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt  = 1;
        ListNode* t = head;
        if(head== NULL)
            return NULL;

        if( head->next == NULL)
            return head;
        
        while(cnt != k && t != NULL){
                t= t->next;
                cnt++;
                if(t->next == NULL)
                    break;
        }
        cout<< cnt<<" " << head->val<<endl;
        if(cnt != k)
            return head;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = curr->next;


        cnt = k-1;
        // cout<< cnt<<endl;

        while(cnt != 0 && curr != NULL ){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(curr!=NULL)
                nxt = curr->next;
            cnt--;
        }

        head->next = reverseKGroup(curr, k);
        return prev;
        
    }
};



//  codestudio Solution:

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node* reverseKGroup(Node* head, int *b , int n ,  int p) {
        int cnt  = 1;
        Node* t = head;
        if(head== NULL)
            return NULL;

        if(p == n || head->next == NULL)
            return head;
		if(b[p] == 0)
			return reverseKGroup(head,b,  n, p +1);
        int k = b[p];
		
        // while(cnt != k && t != NULL){
        //         t= t->next;
        //         cnt++;
        //         if(t->next == NULL)
        //             break;
        // }
        // cout<< cnt<<" " << head->val<<endl;
        // if(cnt != k)
        //     return head;

        Node* prev = head;
        Node* curr = head->next;
        Node* nxt = curr->next;


        cnt = k-1;
        // cout<< cnt<<endl;

        while(cnt != 0 && curr != NULL ){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(curr!=NULL)
                nxt = curr->next;
            cnt--;
        }

        head->next = reverseKGroup(curr, b , n , p+1);
        return prev;
        
    }

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	return reverseKGroup(head , b , n , 0);
}