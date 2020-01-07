#include <stdio.h>
#include "dijkstra.h"



//initialize vertices shorest path to infinity
void initi(void)
{
    VShP[1] = 0;
    for(int i = 2;i < V; i++)
        VShP[i] = infinity;
}


// add vertices to spSet
void spSetEdges(Item *v)
{
    Item *t = v;
    visited[v->value] = 1;
    spSet[v->value] = 0;
    while (t!= NULL)
    {
        if(visited[t->value] != 1)
        {
            spSet[t->value] = 1;
            update(t,VShP[v->value]+t->length);
        }
        t= t->next;
    }
    
}




// choose the smallest vertex
int edgeCh(void)
{
    int s = 0;
    while (s < V){
        if(spSet[s] == 1)
            break;
        s++;
    }
    for(int i =1; i < V; i++)
    {
        if(spSet[i] == 1 && (VShP[s] == infinity || VShP[s] > VShP[i]))
        {
            s = i;
        }
    }
    return s;
}



//update the shortest path of a vertex
void update(Item* k ,int s)
{
    if(VShP[k->value] == infinity)
        VShP[k->value] = s;
    
    else if(VShP[k->value] > s )
        VShP[k->value] = s;
}





