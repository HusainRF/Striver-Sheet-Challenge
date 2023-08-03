#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* h1, Node<int>* h2)
{
    // Write your code here.
     if(h1 == NULL)
            return h2;
        if(h2 == NULL)
            return h1;
        Node<int> *head = new Node<int>(-100);
        Node<int> *t = head;
        while(h1 != NULL && h2 != NULL){
            if(h1->data < h2->data){
                Node<int>* temp = new Node<int>(h1->data);
                t->next = temp;
                t = temp;
                h1 = h1->next;
            }
            else{
                Node<int>* temp = new Node<int>(h2->data);
                t->next = temp;
                t = temp;
                h2 = h2->next;
            }
        }
        if(h1 != NULL)
            t->next = h1;
        if(h2 != NULL)
            t->next = h2;
        
        return head->next;

}
