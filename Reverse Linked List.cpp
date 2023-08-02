#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
        if(head == NULL)
            return NULL;

        LinkedListNode<int>* prev = head;
        if(head->next == NULL)
            return head;

        LinkedListNode<int>* curr = head->next;

        prev->next = NULL;
        if(curr->next == NULL){
            curr->next = prev;
            head = curr;
            return head;
        }
     LinkedListNode<int>* nxt = curr->next;
        while(curr->next != NULL){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = curr->next;
            head = curr;
        }
        curr->next = prev;
        
    return head;
}