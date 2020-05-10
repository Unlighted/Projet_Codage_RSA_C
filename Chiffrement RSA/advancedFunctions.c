#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "basicFunctions.h"
#include "advancedFunctions.h"

void distributeAll(unsigned int *nombre, int size, int value){
    int i, mult = (int)pow(10, SIZECELL);

    if(size==1)
        value=0;
    if(nombre[0]<value)
        value = nombre[0];

    nombre[0] -= value;
    for(i=1; i<size-1; i++){
        nombre[i] += value * mult - value;
    }

    nombre[i] += value * mult;
}
int subNumber(unsigned int *numberA, int sizeA, unsigned int *numberB, int sizeB, unsigned int **numberC){
    int  sizeC, i;

    if(sizeB>sizeA || (sizeB==sizeA && numberB[0]>numberA[0]))
        return 0;

    sizeC = (sizeA>sizeB) ? sizeA : sizeB;
    allocateNumber(numberC, sizeC);

    for(i=0; i<sizeA&&i<sizeB; i++){
        if((int)(numberA[sizeA-i-1]-numberB[sizeB-i-1])<0){
            distributeAll(&(numberA[sizeA-i-2]), 2, 1);
        }
        (*numberC)[sizeC-i-1]=numberA[sizeA-i-1]-numberB[sizeB-i-1];
    }
    while(i<sizeC){
        (*numberC)[sizeC-i-1]=numberA[sizeA-i-1];
        i++;
    }
    sizeA=rearrangeNumber(&numberA, sizeA);
    sizeC=rearrangeNumber(numberC,sizeC);
    return sizeC;
}

int isModOf(unsigned int *bigNumber, int sizeBigNumber, unsigned int *smallNumber, int sizeSmallNumber, unsigned int **remainder){
    unsigned int *tempSmallNumber, *buffer, *quotient;
    int sizeRemainder, sizeTempSmallNumber, sizeQuotient, j;
    unsigned int copyWithAdd = 0;
    sizeRemainder = addNumber(bigNumber, sizeBigNumber, &copyWithAdd, 1, remainder);
    distributeAll(*remainder, sizeRemainder, remainder[0]);

    while(sizeRemainder > sizeSmallNumber + 1){

        distributeAll(*remainder, sizeRemainder, remainder[0]);
    }
    return sizeRemainder;
}

int getPrimeNumber(unsigned int *bigNumber, int sizeBigNumber, unsigned int **primeNumber){
    unsigned int *testNumber, *bufferBigNumber, *buffer;
    int sizeTestNumber, sizePrimeNumber, sizeBufferBigNumber, sizeBuffer, i;
    unsigned int copyWithAdd = 0;
    sizePrimeNumber = sizeBigNumber;
    allocateNumber(primeNumber, sizePrimeNumber);

    do{
        do{
            (*primeNumber)[0] = rand() % (int)pow(10, SIZECELL);
        } while((*primeNumber)[0] >= bigNumber[0]);
        for(i=1; i<sizeBigNumber; i++)
            (*primeNumber)[i] = rand() % (int)pow(10, SIZECELL);

        sizeTestNumber = addNumber((*primeNumber), sizePrimeNumber, &copyWithAdd, 1, &testNumber);
        sizeBufferBigNumber = addNumber(bigNumber, sizeBigNumber, &copyWithAdd, 1, &bufferBigNumber);

        while(sizeTestNumber != 1 || testNumber[0] > 1){
            sizeBuffer = isModOf(bufferBigNumber, sizeBufferBigNumber, testNumber, sizeTestNumber, &buffer);
            sizeBufferBigNumber = addNumber(testNumber, sizeTestNumber, &copyWithAdd, 1, &bufferBigNumber);
            sizeTestNumber = addNumber(buffer, sizeBuffer, &copyWithAdd, 1, &testNumber);
        }

    } while(sizeTestNumber != 1 || testNumber[0] != 1);
    return sizePrimeNumber;
}
