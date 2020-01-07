#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#include "Union-Find.h"


int maxSpacing(edge* head,int parent[]);
void read(edge* h);
edge* head;


int main(void)
{
    head = malloc(sizeof *head);
    read(head);
    MergeSort(&head);
    
    
    
    int size[head->obj1+1];
    int parent[head->obj1+1];
    initParent(parent,head->obj1+1);
    
    
    int count = head->obj1 - 4;
    
    while(count > 0)
    {
        edge* t =head->next;
        if(find(parent,t->obj1) != find(parent,t->obj2))
        {
            Union(parent ,size,t->obj1,t->obj2);
            count--;
        }
       
        
        deleteEdge(head);
    }
    
    
    //printList(head);
    printf("max spacing = %d \n",maxSpacing(head,parent));
    
}




int maxSpacing(edge* head,int parent[])
{
    int max = 1000000;
    edge* t =head->next;
    while(t != NULL)
    {
        if(max > t->distance && find(parent,t->obj1) != find(parent,t->obj2))
            max = t->distance;
        t= t->next;
    }
    
    return max;
}


void read(edge* h)
{
    int obj1 = 0;
    int obj2 = 0;
    int distance = 0;
    FILE* file = fopen("clustering1.txt","r");
    char* line;
    size_t n=0;
    
    
    while(getline(&line,&n, file) != -1)
    {
        
        sscanf(line,"%d %d %d",&obj1,&obj2,&distance);
        if(distance == 0)
            h->obj1 = obj1;
        else
            insert(h,obj1,obj2,distance);
        
        
    }
}
