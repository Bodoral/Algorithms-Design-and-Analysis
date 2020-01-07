#include <stdio.h>

int indexh = 0;
int disHeap[9];
void heapAdd(int n);
int removeHeap(void);
void adjust(int n);

void heapAdd(int n)
{
  disHeap[indexh] = n;
  int s = indexh;
  indexh++;
  while(s != 0 && disHeap[s] < disHeap[s/2])
	{
	  int t = disHeap[s/2];
	  disHeap[s/2] = disHeap[s];
	  disHeap[s] = t;
	  s = s/2;
	}
    
}


int removeHeap(void)
{
  int min = disHeap[0];
  indexh--;
  disHeap[0] = disHeap[indexh];
  printf(" %d\n",disHeap[0]);
  adjust(0);
  return min;
}


void adjust(int n)
{
  if((n*2)+1 >= indexh)
    return;

  else if(disHeap[n] > disHeap[(n*2) + 1] || disHeap[n] > disHeap[(n*2)+2])
    {
      int r = disHeap[(n*2) + 1] < disHeap[(n*2)+2]? (n*2)+1:(n*2)+2;
      int t = disHeap[r];
      disHeap[r] = disHeap[n];
      disHeap[n] = t;
      printf("disHeap[r] = %d r = %d\n",disHeap[r] ,r);
      adjust(r);
    }
}
