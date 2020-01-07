#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "prim.h"



//display the list
void printList() {
  struct node *ptr;
    
    for(int i = 1; i <= MAX;i++)
    {
        printf("\nleve = %d \n",i);
        
        ptr = graph[i];
        while(ptr != NULL)
        {
            printf("(%d,%d)\t ",ptr->n,ptr->cost);
            ptr = ptr->next;
        }
    }
    
    printf("\n-------------------\n");
}





void insertFirst(int h,int cost, int n) {
    
  //create a link
  struct node *link = (struct node*) malloc(sizeof(struct node));
  
  link->cost = cost;
  link->n = n;
  
  //point it to old first node
  link->next = graph[h];
  
  //point first to new first node
  graph[h] = link;
}



struct node* deleteFirst(struct node *h) {

  //save reference to first link
  struct node *tempLink = h;
  
  //mark next to first link as first 
  h = h->next;
  
  //return the deleted link
  return tempLink;
}




