#include <stdio.h>
#include <string.h>
#include "Dijkstra.h"

Item* vertex ;
int main(void)
{
    readFile();
    printR(graph);
    
    initi();
    
    
    vertex = &graph[1];
    int j = V;
    while(j > 1)
    {
        
        spSetEdges(vertex);
        vertex = &graph[edgeCh()];
        j--;
    }
    
    
    //print result
    PrintINT();
}

