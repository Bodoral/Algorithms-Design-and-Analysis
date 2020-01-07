
#define V 201
#define infinity 1000000
struct linked_List
{
  int value,length;
  struct linked_List *next;
};

typedef struct linked_List Item;



Item graph[V];
int spSet[V];
int visited[V];
int VShP[V];



// Main Functions
void readFile(void);
void insert(Item List[],int i,int v,int length);
void printR(Item list[]);

//Dijkstras algorithm functions
void initi(void);
void spSetEdges(Item *v);
int edgeCh(void);
void update(Item* k ,int s);
void PrintINT(void);