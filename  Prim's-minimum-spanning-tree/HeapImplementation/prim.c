#include <stdio.h>
#include "prim.h"

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

struct node key[MAX];
int size = MAX-1;
void graphIniti(void)
{
    for(int i = 1; i <= MAX ;i++)
    {
        key[i].n = i;
        key[i].cost = INF;
    }
    
}

// find minimum spanning tree using Prim's Algorithm
void prim(void)
{
    //total cost
    int cost =0;
    
    
    key[1].cost = 0;
    heapify(1);
    int j =0 ;
    while(size > 0)
    {
        
      int node = smallest(&cost);
      visited[node] = 1;
      updateKey(node);
        
    }
    
  printf("cost = %d\n",cost);
    
    
}

void heapify(int i) {
    int smallest = (LCHILD(i) < size && key[LCHILD(i)].cost < key[i].cost) ? LCHILD(i) : i ;
    if(RCHILD(i) < size && key[RCHILD(i)].cost < key[smallest].cost) {
        smallest = RCHILD(i) ;
    }
    if(smallest != i) {
        swap(i, smallest) ;
        heapify(smallest) ;
    }
}

void swap(int n1, int n2) {
    struct node temp =  key[n1] ;
    key[n1]= key[n2] ;
    key[n2] = temp ;
}

//update key if we find edge smaller than the previous
void updateKey(int n)
{
    struct node* t = graph[n];
    
    while(t != NULL)
    {
        
        
            if(visited[t->n] != 1)
                lessThan(t->n,t->cost);
        
            t= t->next;
    }
}

void lessThan(int node, int cost)
{
    for(int i =1; i<= size;i++)
        if(key[i].n == node)
        {
            if(key[i].cost > cost)
            {
                key[i].cost = cost;
                heapify(1);
            }
            break;
        }
}
//find the smallest edge
int smallest(int *c)
{

    
    int n = key[1].n;
    *c = *c +key[1].cost;
    key[1]=key[size];
    size--;
    heapify(1);
    return n;
}
