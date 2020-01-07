//TO DO
//
#define SIZE 10007

struct hashTabel_entries
{
  int value;
  struct hashTabel_entries * next;
};
typedef struct hashTabel_entries entry;


entry *buckets[SIZE];

int hashFunction(int v);
void insert(int v);
int delete(int v);
int lookup(int v);
void printHT(void);

