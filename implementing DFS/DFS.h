
#define GV 875715
struct node
{
    int value;
    struct node* next;
};

typedef struct node item;

item ver[GV];
item reverse[GV];
int LSCC[5];

void initi(int n);
void DFSF(item list[],int node);
void DFS_Loop(item list[]);
void reversedGraph(item list[]);
void printR(item list[]);
void readFile(void);
void insert(item List[],int i,int v);
void largestSCC(int size);
