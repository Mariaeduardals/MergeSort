
typedef struct produto Produto;

typedef struct merge Merge;

Produto* novoProduto(int codigo, float valor);

Merge* create(int n);

int add(Merge* v, int codigo, float valor);

void merge(Merge *v,int inicio, int meio, int final);

void mergeSort(Merge *v,int start,int end);

int getArraySize(Merge*);

void imprimir(Merge *v);
