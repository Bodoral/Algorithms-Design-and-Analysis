#include <stdio.h>
#include <stdlib.h>
#include"HashTable.h"



//Hash 
int hash(int v)
{
  return (v < 0? v%SIZE *-1: v%SIZE);
  //return v%SIZE;
}


// insert element v into HashTable
void insert(int v)
{
  if(buckets[hash(v)] == NULL)
    {
      entry *t = malloc(sizeof(*t));
      t->value = v;
      buckets[hash(v)] =t;}
  else 
    {
      entry *t = malloc(sizeof(*t));
      t->value = v;
      t->next = buckets[hash(v)];
      buckets[hash(v)] =t;
    }
     
}



//delete element v form the hashTable
int delete(int v)
{
  int r =0;
  if(buckets[hash(v)] != NULL)
    {
      entry *t = buckets[hash(v)];
      entry **tk = &buckets[hash(v)];
      while(t!= NULL)
	{
	  if(t->value == v)
	    {
	      r = t->value;
	      *tk = t->next;
	      break;
	    }
	  tk = &((*tk)->next);
	  t= t->next;
	}
    }

  return r;
}



// look for an element v
int lookup(int v)
{
  int r =0;
  if(buckets[hash(v)] != NULL)
    {
      entry *t = buckets[hash(v)];
      //entery *tk = t;                                                         
      while(t != NULL)
        {
          if(t->value == v)
            {
              r = t->value;
	      break;
            }

	  t = t->next;
	}
    }
  return r;

}


// print hash table

void printHT(void)
{
    
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d | \t",i);
        entry *t = buckets[i];
        while(t != NULL)
        {
            printf("%d \t ", t->value);
            t = t->next;
        }
        printf("\n");
    }
    
    
    
}
