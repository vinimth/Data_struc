//-----------------------------------------------------
// Estrutura de Dados
//
// Título: Lista de Exercícios 01
//
// Equipe:
// Ariel Citrangulo Pereira Alves RA: 1821517260
// Anderson de Sousa              RA: 1821518517
// Vinicius Matheus Santos Moreno RA: 171152761
//
// Data: 10/09/2019
//-----------------------------------------------------

#include "TData.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

TData* dataCreate() {
    TData *newData = malloc(sizeof(TData));

    if (newData) {
        newData->RA = malloc(sizeof(int));
        newData->nome = malloc(SIZENOME * sizeof(char));
        newData->nota = malloc(sizeof(int));
    }
    return newData;
}

void dataSetFields(TData* data, int RA, char* nome, int nota) {
    data->RA = RA;
    data->nome = nome;
    data->nota = nota;
}

TData* dataCreateFields(int RA, char* nome, int nota) {
    TData *newData;
    newData = dataCreate();

    dataSetFields(newData, RA, nome, nota);

    return newData;
}

void dataDefault(TData* data) {
    dataSetFields(data, 123, "Default", 0);
}

void dataPrintHeader() {
    printf("==============================================================\n");
    printf("   RA     Nome                                  Nota\n");
    printf("==============================================================\n");
}

void dataFree(TData* data) {
    if (data) {
        free(data->RA);
        free(data->nome);
        free(data->nota);

        free(data);
    }
}

void dataPrint(TData* data) {
    if (data) {
        int i;

        printf("%  d", data->RA);
        printf("     %s", data->nome);

        int espaco = SIZENOME - strlen(data->nome);
        for (i = 0; i < espaco; i++) {
            printf(" ");
        }

        printf("%d\n", data->nota);
    }
}

void dataRand(TData* data) {
    int RA = rand() % 999;
    int nota = rand() % 11;
    int nomeCode = rand() % 123;

    char* nome = malloc(SIZENOME * sizeof(char));
    sprintf(nome, "%d", nomeCode);
    strcat(nome, " NOME");
    dataSetFields(data, RA, nome, nota);
}

void dataCopy(TData* dataDest, TData* dataSource) {
    dataDest->RA = dataSource->RA;
    dataDest->nome = dataSource->nome;
    dataDest->nota = dataSource->nota;
}

TData* dataClone(TData* dataSource) {
    TData* newData;
    newData = dataCreate();
    dataCopy(newData, dataSource);
    return newData;
}

void dataSwap(TData* dataA, TData* dataB) {
    TData* aux;
    aux = dataClone(dataA);
    dataCopy(dataA, dataB);
    dataCopy(dataB, aux);

    dataFree(aux);
}

int dataComp(TData* dataA, TData* dataB, int idField) {
    if (idField == 0) {
        return dataA->RA - dataB->RA;
    } else if (idField == 1) {
        return strcmp(dataA->nome, dataB->nome);
    } else {
        return dataA->nota - dataB->nota;
    }
}
