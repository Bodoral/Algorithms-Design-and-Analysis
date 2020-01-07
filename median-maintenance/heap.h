#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2


typedef struct node {
  int data ;
} node ;

typedef struct maxHeap {
  int size ;
  node *elem ;
} maxHeap ;


typedef struct minHeap {
  int size ;
  node *elem ;
} minHeap ;




void swap(node *n1, node *n2);



/*
  Max Heap Functions
*/

maxHeap initMaxHeap(int size);
void heapifyM(maxHeap *hp, int i);
void buildMaxHeap(maxHeap *hp, int *arr, int size);
void insertNodeM(maxHeap *hp, int data);
void deleteNodeM(maxHeap *hp);
int getMinNode(maxHeap *hp, int i);
void deleteMaxHeap(maxHeap *hp);



/*
  Min Heap Functions
*/
minHeap initMinHeap(int size);
void heapify(minHeap *hp, int i);
void buildMinHeap(minHeap *hp, int *arr, int size);
void insertNode(minHeap *hp, int data);
void deleteNode(minHeap *hp);
int getMaxNode(minHeap *hp, int i);
void deleteMinHeap(minHeap *hp);
