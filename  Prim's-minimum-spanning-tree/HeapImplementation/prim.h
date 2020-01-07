
// MAX = number of element + 1
#define MAX 501
#define INF 10000


struct node {
    int n;
    int cost;
    struct node *next;
};





int visited[MAX];
struct node* graph[MAX];






/*
 Linked list functions
 */
void printList();
void insertFirst(int h,int cost, int n);
struct node* deleteFirst(struct node *h);


/*
 Prim's Algorithm functions
 */
void prim(void);
void updateKey(int n);
int smallest();
//heap functions
void lessThan(int node, int cost);
void swap(int n1, int n2);
void heapify(int i);

