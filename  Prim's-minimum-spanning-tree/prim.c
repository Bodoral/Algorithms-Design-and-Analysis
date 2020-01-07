#include <stdio.h>
#include "prim.h"
int key[MAX+1]= { [ 0 ... MAX ] = INF};


//minimum spanning tree using Prim's Algorithm
void prim(void)
{
    //total cost
    int cost =0;
    
    
  key[1] = 0;
    

  int j =0 ;
  while(j< (MAX-1))
    {
        
      int node = smallest(&cost);
      visited[node] = 1;
      updateKey(node);
      j++;
        
    }
    
  printf("cost = %d\n",cost);
    
    
}


//update key if we find edge smaller than the previous
void updateKey(int n)
{
    struct node* t = graph[n];
    
    while(t != NULL)
    {
        
        
            if(t->cost < key[t->n] && visited[t->n] != 1)
                key[t->n]= t->cost;
        
            t= t->next;
    }
}


//find the smallest edge
int smallest(int *c)
{
 
    int n = 0;
    int cost = INF;
    
    for(int i = 1; i < MAX; i++)
        if(cost > key[i] && visited[i] != 1)
        {
            cost = key[i];
            n = i;
        }
    
    
  *c = *c +cost;
  return n;
}
