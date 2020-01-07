#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dijkstra.h"



//read file line by line 2 elemant each time;
void readFile(void)
{
    int i = 1;
    FILE* file = fopen("dijkstraData.txt","r");
    char* line;
    
    size_t n=0;
    while(getline(&line,&n, file) != -1)
    {
        
        char* sub = strtok(line,"\t");
        sscanf(sub,"%d",&i);
        
        while(sub!= NULL)
        {
            int in = 0;
            int j = 0;
            sscanf(sub,"%d,%d",&in,&j);
            insert(graph,i,in,j);
            sub= strtok(NULL,"\t");
        }
    }
}




// insert from file to array
void insert(Item List[],int i,int v,int length)
{
    //Item* t = List[i].next;
    
    if(i == v)
    {
        List[i].value = v;
        List[i].length = length;
        //List[i].next = NULL;
    }
    else{
    Item* k = (Item*)malloc(sizeof(Item));
    k->value = v;
    k->length = length;
    k->next = List[i].next;
        List[i].next = k;}

    
}

//take an array of items and print it;
void printR(Item list[])
{
    Item *k = NULL;
    for(int i =1 ; i< V; i++)
    {
        k = list[i].next;
        while(k != NULL)
        {
            printf("%d\t%d\n",k->value,k->length);
            k = k->next;
        }
        printf("------------------\n");
    }
}



void PrintINT(void)
{

//    for(int i = 1; i < V ;i++)
//    {
//        printf("%d \n",VShP[i]);
//        
//    }
        printf("%d \t",VShP[7]);
    printf("%d \t",VShP[37]);
    printf("%d \t",VShP[59]);
    printf("%d \t",VShP[82]);
    printf("%d \t",VShP[99]);
    printf("%d \t",VShP[115]);
    printf("%d \t",VShP[133]);
    printf("%d \t",VShP[165]);
    printf("%d \t",VShP[188]);
    printf("%d \n",VShP[197]);
}



