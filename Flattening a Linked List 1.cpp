
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node *flatten(Node *root)
{
   // Your code here
   priority_queue<pair<int ,Node*>> pq;
   if(root == NULL)
    return root;
    
   pq.push({-1*root->data , root});
   Node* head = new Node(-1);
   Node* t = head;
   while(pq.size() != 0){
       auto itr = pq.top();
       pq.pop();
       Node* temp =new Node(itr.first * (-1));
       t->bottom = temp;
       t= t->bottom;
       Node* nd = itr.second;
       
       if(nd->next != NULL){
           pq.push({-1* nd->next->data , nd->next });
       }
       if(nd->bottom != NULL){
           pq.push({-1* nd->bottom->data , nd->bottom });
       }
   }    
   return head->bottom;
}




