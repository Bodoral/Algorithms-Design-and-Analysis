#include <stdio.h>
#include "heap.h"

int MedMain(void);
maxHeap* low;
minHeap* high;
int lowSize = 0;
int highSize = 0;
int result = 0;
int m = 0;

int main(void)
{
    
    //low heap is amx heap and store  numbers lees than median
    maxHeap maxy = initMaxHeap(10000);
    low = &maxy;
    
    //high heap is min heap and it store numbers less than median
    minHeap miny = initMinHeap(5003);
    high = &miny;
    
    // error when i remove this line and i dont know why
    printf("Median Miantenance\n");
    
    
    int r = MedMain();
    printf("result = %d \n",result%10000);
    
}

int MedMain(void)
{
    // reading from file
    int i = 1;
    FILE* file = fopen("Median.txt","r");
    char* line;
    size_t n=0;
    while(getline(&line,&n, file) != -1)
    {
        
        sscanf(line,"%d",&i);
        
        //insert element into low heap if it was the first element or less than median
        if(i <= m || lowSize == 0)
        {
            insertNodeM(low, i);
            lowSize++;

            //balence btween the tow heaps
            if(lowSize > highSize+1)
            {
                insertNode(high,low->elem[0].data);
                deleteNodeM(low);
                highSize++;
                lowSize--;
            }
        }
        
        
        
        //insert element into high heap if it was greater than median
        else if(i > m)
        {
            insertNode(high, i);
            highSize++;
            
            //balence btween the tow heaps
            if(lowSize < highSize)
            {
                insertNodeM(low, high->elem[0].data);
                deleteNode(high);
                highSize--;
                lowSize++;
            }
            
        }
        
        
        
        m = low->elem[0].data;
        result += m;
        
        
    }
    return result;
    
}
