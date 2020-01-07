
/* Dijkstra Algorithm for finding shortest path 
 Heap implementation*/


#include <stdio.h>
#include <string.h>
#include "Dijkstra.h"

Item* vertex;
int main(void)
{
    readFile();
    printR(graph);
    
    
    
    initi();
    vertex = &graph[removeHeap()];
    int j = V;
    
    while(indexh >= 0)
    {
        spSetEdges(vertex);
        vertex = &graph[removeHeap()];
        j--;
    }
    
    //print the result 
    PrintINT();
}

