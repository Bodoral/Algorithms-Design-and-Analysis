#include <stdio.h>
#include "Dijkstra.h"

// add to the last then move it to it is right place
void heapAdd(int n)
{
    disHeap[indexh] = n;
    int s = indexh;
    indexh++;
    while(s != 0 && VShP[disHeap[s]] < VShP[disHeap[s/2]])
    {
        int t = disHeap[s/2];
        disHeap[s/2] = disHeap[s];
        disHeap[s] = t;
        s = s/2;
    }
    
}

//remove the root which is the smallest key in the heap
int removeHeap(void)
{
    int min = disHeap[0];
    indexh--;
    disHeap[0] = disHeap[indexh];
        adjust(0);
    return min;
}


void adjust(int n)
{
    if((n*2)+2 >= indexh)
        return;
    
    else if(VShP[disHeap[n]] > VShP[disHeap[(n*2)+1]] || VShP[disHeap[n]] > VShP[disHeap[(n*2)+2]])
    {
        int r = VShP[disHeap[(n*2)+1]] < VShP[disHeap[(n*2)+2]]? (n*2)+1:(n*2)+2;
        int t = disHeap[r];
        disHeap[r] = disHeap[n];
        disHeap[n] = t;
        adjust(r);
    }
}

//update a key
void kupdate(int n)
{
    for(int i = 0;i <indexh ;i++)
        if(n == disHeap[i])
        {
            int s = i;
            while(s != 0 && VShP[disHeap[s]] < VShP[disHeap[s/2]])
            {
                int t = disHeap[s/2];
                disHeap[s/2] = disHeap[s];
                disHeap[s] = t;
                s = s/2;
            }
        }
}
