#include <stdio.h>
#include<string.h>
#include<stdio.h>
#define MAX 10000



typedef struct elem
{
    int l,w,s;
}element;

element jobs[MAX];

void reader();
void weightedCompletion();
void merge(element arr[], int l, int m, int r);
void mergeSort(element arr[], int l, int r);





int main(void)
{
    
    reader();
    mergeSort(jobs,0,MAX-1);
    weightedCompletion();
    
    
    
}



//count and print result;
void weightedCompletion()
{
    long c = 0;
    long wei = 0;
    for(int i = 0;i < 10000; i++)
    {
        
        c +=jobs[i].l;
        wei +=(c*jobs[i].w);
    }
    printf(" sum of weighted completion times %ld\n",wei);
}








/* 
    Merge Sort Functions

 */

void merge(element arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    /* create temp arrays */
    element L[n1], R[n2];
    
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].s > R[j].s)
        {
            arr[k] = L[i];
            i++;
        }
        else if(L[i].s ==  R[j].s)
        {
            if(L[i].w >  R[j].w)
            {
                arr[k] = L[i];
                i++;
            }
            
            else
            {
                arr[k] = R[j];
                j++;
            }
        
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(element arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        
        merge(arr, l, m, r);
    }
}




// reads input from a file;
void reader()
{
    int index = 0;
    int i = 1;
    FILE* file = fopen("jobs.txt","r");
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
            sscanf(sub,"%d %d",&in,&j);
            jobs[index].w = in;
            jobs[index].l = j;
            jobs[index].s = in/j;
            sub= strtok(NULL,"\t");
            
        }
        index++;
    }

}