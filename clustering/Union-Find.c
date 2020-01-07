#include <stdio.h>
#include "Union-Find.h"

void initParent(int parent[],int size)
{
    for(int i = 1; i < size; i++ )
    {
        parent[i] = i;
    }
}





int find(int parent[], int i)
{
  if (parent[i] != i)
    parent[i] = find(parent, parent[i]);
 
  return parent[i];
}





void Union(int parent[],int sz[], int x, int y)
{
  int xroot = find(parent, x);
  int yroot = find(parent, y);
 
  // Attach smaller rank tree under root of high rank tree
  // (Union by Rank)
  if (sz[xroot]< sz[yroot])
    parent[xroot]= yroot;
  else if (sz[xroot] > sz[yroot])
    parent[yroot]= xroot;
 
  // If ranks are same, then make one as root and increment
  // its rank by one
  else
    {
      parent[yroot] = xroot;
      sz[xroot]++;
    }
}
