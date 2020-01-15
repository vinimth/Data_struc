#ifndef TDataH
#define TDataH
#define SIZENOME 40

typedef struct TData
{
    int RA;
    char* nome;
    int nota;
} TData;

TData* dataCreate();
TData* dataCreateFields(int RA, char* nome, int nota);
TData* dataClone(TData* dataSource);
void dataPrintHeader();
void dataPrint(TData *data);
void dataDefault(TData* data);
void dataSetFields(TData* data, int RA, char* nome, int nota);
void dataRand(TData* data);
void dataCopy(TData* dataDest, TData* dataSource);
void dataSwap(TData* dataA, TData* dataB);
void dataFree(TData *data);
int dataComp(TData* dataA, TData* dataB, int idField);

#endif
