//-----------------------------------------------------
// Estrutura de Dados
//
// Título: Lista de Exercícios 01
//
// Equipe:
// Ariel Citrangulo Pereira Alves RA: 1821517260
// Anderson de Sousa              RA: 1821518517
// Vinicius Matheus Santos Moreno RA: 171152761
// Data: 10/09/2019
//-----------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "TData.h"

int main()
{
    TData* dataRandom = dataCreate();
    TData* data = dataCreateFields(123, "Teste Data", 8);

    dataPrintHeader();
    dataPrint(data);

    dataDefault(data);
    dataPrint(data);

    printf("\n");
    srand(time(NULL));

    dataRand(dataRandom);
    dataPrint(dataRandom);

    return 0;
}
