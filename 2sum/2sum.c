#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "HashTable.h"


#define S 1000000

#define Lm 10000
#define Sm -10000

int nArray[S];
int tArray[Lm-Sm];

int main(void)
{
  int target = 0;
  int index = 0;
    
    
  // reading from file
  int i = 1;
  FILE* file = fopen("2sum.txt","r");
  char* line;
  size_t n=0;
  while(getline(&line,&n, file) != -1)
    {
        
      char* sub = strtok(line,"\t");
      sscanf(sub,"%d",&i);
      //printf("%d \n",i);
      nArray[index] = i;
      insert(i);
      index++;
    }


    for(int u = Sm; u <= Lm; u++)
    {
        
        for(int j = 0;j < S; j++)
        {
            int k = lookup(u - nArray[j]);
            if(k != 0 && k != nArray[j])
            {
                //printf("%d + %d \n",nArray[j],k);
                target++;
                break;
            }
                
        }
        //printf("%d\n",u+1);
    }
    
    printf("%d\n",target);

}
