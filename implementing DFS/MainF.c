#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DFS.h"


//read file line by line
void readFile(void)
{
    int i = 1;
    FILE* file = fopen("SCCt.txt","r");
    char* line;
    size_t n=0;
    while(getline(&line,&n, file) != -1)
    {
        
        char* sub = strtok(line," ");
        sscanf(sub,"%d",&i);
        while(sub!=NULL)
        {
            int n;
            sscanf(sub,"%d",&n);
            insert(ver,i,n);
            sub= strtok(NULL," ");
        }
    }
    
}




// insert from file to array
void insert(item List[],int i,int v)
{
    if(i != v)
    {
        item *t = &List[i];
        item *k;
        
        while (t!= NULL)
        {
            k = t;
            t = t->next;
            
        }
        
        item *n=(item*)malloc(sizeof(item));
        n->value = v;
        n->next = NULL;
        k->next = n;
        
    }
    
}




//take an array of items and print it;
void printR(item list[])
{
    item *k = NULL;
    for(int i =1 ; i< GV; i++)
    {
        k = list[i].next;
        while(k != NULL)
        {
            printf("%d \n",k->value);
            k = k->next;
        }
        printf("------------------\n");
    }
}