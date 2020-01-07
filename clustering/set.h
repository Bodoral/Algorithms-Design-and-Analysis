
/*
 Linked list 
 
    insert --> insert at the begining
 
    deleteEdge --> can be used only to delete the first element in the list
 
    MergeSort --> sort the list by distance
 */


typedef struct edges
{
  int obj1,obj2,distance;
  struct edges* next;
}edge;


void insert(edge *head,int obj1,int obj2,int distance);
void deleteEdge(edge* pre);
void printList(edge* head);


/*
    merge Sort functions
 */
void MergeSort(edge** headRef);
void FrontBackSplit(edge* source,edge** frontRef, edge** backRef);
edge* SortedMerge(edge* a, edge* b);