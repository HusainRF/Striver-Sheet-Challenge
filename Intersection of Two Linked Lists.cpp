/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/
#include <bits/stdc++.h>

Node* findIntersection(Node *headA, Node *headB)
{
    //Write your code here
     unordered_map<Node* , int> mp;
        Node* t1 = headA;
        Node *t2 = headB;

        while(t1 != NULL){
            mp[t1] =1;
            t1 = t1->next;
        }

        while(t2 != NULL)
        {
            if(mp.count(t2))
                return t2;
            t2= t2->next;
        }

        // Node* node = new Node(0);

        return NULL;
}
