#include <stdio.h>
#include "DFS.h"



item* b =NULL;
int main(void)
{

    readFile();
    initi(2);
  
    reversedGraph(ver);
    DFS_Loop(reverse);

    initi(1);
    DFS_Loop(ver);
    
    for(int i = 0; i <5; i++)
        printf("%d\n",LSCC[i]);
    
        
    
}




