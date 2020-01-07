#include <stdio.h>
#include "Dijkstra.h"

//initialize  vertices shorest path to infinity + initialize the heap
void initi(void)
{
  VShP[1] = 0;
  for(int i = 2;i < V; i++)
    VShP[i] = infinity;
    
  indexh = 0;
    for(int j = 0;j < V ;j++)
        heapAdd(j);
}



// find edges
void spSetEdges(Item *v)
{
  Item *t = v;
  visited[v->value] = 1;
  while (t!= NULL)
    {
      if(visited[t->value] != 1)
        {
            update(t,VShP[v->value]+t->length);
            
        }
      t= t->next;
    }
    
    
}


//update the shortest path of a vertex
void update(Item* k ,int s)
{
    if(VShP[k->value] == infinity){
    VShP[k->value] = s;
        kupdate(k->value);
    }
    else if(VShP[k->value] > s ){
    VShP[k->value] = s;
    kupdate(k->value);
    }
}
