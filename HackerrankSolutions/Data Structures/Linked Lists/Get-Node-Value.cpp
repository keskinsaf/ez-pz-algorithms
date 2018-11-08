/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
    Node* traverse = head;
    int ctr = 0;
    while( traverse->next != NULL ){
        traverse = traverse->next;
        ctr++;
    }
    traverse = head;
    for( int i = 0; i < ctr - positionFromTail; i++ )
        traverse = traverse->next;
    return traverse->data;
}
