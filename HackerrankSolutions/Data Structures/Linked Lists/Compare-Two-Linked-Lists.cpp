/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
    Node *t1 = headA, *t2 = headB;
    while( t1 != NULL ){
        if( t2 == NULL )
            return 0;
        if( t1->data == t2->data ){
            t1 = t1->next; t2 = t2->next;
        }else
            return 0;
    }
    if( t2 == t1 )
        return 1;
    return 0;
}
