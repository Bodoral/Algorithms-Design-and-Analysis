#include<stdio.h>
#include "DFS.h"

int visited[GV];
int finishingTime[GV*2];
int vArrang[GV];

int fTime = 0;
int s;




//  initialize and reset some arrays input 2 for  initializing  1 for reset
void initi(int n )
{
    if(n == 2)
    for(int i =0 ; i < GV;i++)
    {
        visited[i] = 0;
        vArrang[i] = i;
        finishingTime[i] = i;
        ver[i].value = i;
        reverse[i].value = i;
    }
    
    else
        for(int i = 0;i <GV;i++)
        {
            visited[i] = 0;
            vArrang[i] = finishingTime[i];
            LSCC[i] = 0;
        }
}




void DFSF(item list[], int node)
{
    visited[node] = 1;
    s++;
  item *t = list[node].next;
  while(t != NULL)
    {
        if(visited[t->value] != 1){
            DFSF(list,t->value);}

      t = t->next;
    }
    
    
  fTime++;
  finishingTime[fTime] = node;
  
}





void DFS_Loop(item list[])
{
    
    
  for(int i = GV-1; i > 0; i--)
      
    if(visited[vArrang[i]] != 1)
    {
        s = 0;
      DFSF(list,list[vArrang[i]].value);
        largestSCC(s);
    }

}






// take a graph as an input , reversed and sort it in "reverse" array
void reversedGraph(item list[])
{
    for(int i = 1;i < GV; i++)
    {
        item *t = list[i].next;
        while(t != NULL)
        {
            insert(reverse,t->value,i);
            t = t->next;
        }
    }
}





//compute  the 5 largest SCC in the graph
void largestSCC(int size)
{
    int index = -1 , k =size;
    for(int i = 0; i < 5;i++)
        if(k > LSCC[i])
        {
            k =LSCC[i];
            index = i;
        }
        
    if(index != -1)
        LSCC[index] = size;
}
