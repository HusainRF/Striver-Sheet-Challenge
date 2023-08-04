/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Write your code here.
        int c = 0;
        Node* head = l1;
        Node* prev = l1;

        while(l1 != NULL && l2 != NULL){
            c = l1->data + l2->data + c;
            l1->data = c %10;
            c = c/10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 != NULL){
            if(c != 0){
                while(l1 != NULL){
                    c = c + l1->data;
                    l1->data = c%10;
                    c= c/10;
                    prev = l1;
                    l1 = l1->next;
                }
            }
        }

        if(l2 != NULL){
            l1 = prev;
            l1->next = l2;
            l1 = l1->next;
            
            if( c != 0 ){
                while(l1 != NULL){
                     c = c+ l1->data;
                    l1->data = c%10;
                    c= c/10;
                    prev = l1;
                    l1 = l1->next;
                }
            }
        }
        if(c){
            Node* newnode= new Node(c);
            prev->next = newnode;
        }

        return head;

}
