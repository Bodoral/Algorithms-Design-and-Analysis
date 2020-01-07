#include <stdlib.h>
#include <stdio.h>
#include <set.h>


void insert(edge *head,int obj1,int obj2,int distance)
{

  edge *x = malloc(sizeof *x);
  x->obj1= obj1;
  x->obj2= obj2;
  x->distance = distance;
  x->next = head->next;
  head->next = x;
}



void deleteEdge(edge* head)
{
  edge *x = head->next;
  head->next = head->next->next;
  free(x);  
}


void printList(edge* head)
{
    edge* t = head;
    while(t != NULL)
    {
        printf("obj %d obj %d distance %d \n",t->obj1,t->obj2,t->distance);
        t = t->next;
    }
}



/*
    
 Merge Sort functions
 
 */

void MergeSort(edge** headRef)
{
    edge* head = *headRef;
    edge* a;
    edge* b;
    
   
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    
    
    FrontBackSplit(head, &a, &b);
    
   
    MergeSort(&a);
    MergeSort(&b);
    
    
    *headRef = SortedMerge(a, b);
}



edge* SortedMerge(edge* a, edge* b)
{
    edge* result = NULL;
    
    
    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);
    
    
    if (a->distance <= b->distance)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}


void FrontBackSplit(edge* source,edge** frontRef, edge** backRef)
{
    edge* fast;
    edge* slow;
    if (source==NULL || source->next==NULL)
    {
       
        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        slow = source;
        fast = source->next;
        
       
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        

        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}
