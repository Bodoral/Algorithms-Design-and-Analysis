#include <stdio.h>
#include <string.h>
#include "prim.h"

void read();


int main(void)
{

    read();
    prim();
    
    
}




void read()
{
    int node1 = 0;
    int node2 = 0;
    int cost = 1;
    FILE* file = fopen("edges.txt","r");
    char* line;
    size_t n=0;
    
    
    while(getline(&line,&n, file) != -1)
    {
        
        sscanf(line,"%d %d %d",&node1,&node2,&cost);
        insertFirst(node1,cost,node2);
        insertFirst(node2,cost,node1);
        

    }
   
}

