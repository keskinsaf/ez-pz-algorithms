/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
    Node *retNode, *traverse;
    if( headA || headB ){
        if( headA ){
            if( !headB ){
                retNode = headA;
                headA = headA->next;
            }else if( headA->data < headB->data ){
                retNode = headA;
                headA = headA->next;
            }else{
                retNode = headB;
                headB = headB->next;
            }
        }else{
            retNode = headB;
            headB = headB->next;
        }
    }else
        retNode = NULL;
    traverse = retNode;
    while( headA || headB ){
        if( headA ){
            if( !headB ){
                traverse->next = headA;
                headA = headA->next;
            }
            else if( headA->data < headB->data ){
                traverse->next = headA;
                headA = headA->next;
            }else{
                traverse->next = headB;
                headB = headB->next;
            }
        }else{
            traverse->next = headB;
            headB = headB->next;
        }
        traverse = traverse->next;
    }
    return retNode;
}
