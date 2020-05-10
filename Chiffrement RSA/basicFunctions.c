#include <stdio.h>
#include <stdlib.h>
#include "basicFunctions.h"


int getNumber(unsigned int **number, char numberName){
    char numberS[1000] = {0};
    int i=0, j=-1, sizeNumber=0, sizeNumberInt=0;

    printf("Entrez le nombre %c\n", numberName);
    scanf("%s", numberS);

    for(sizeNumber=0; numberS[sizeNumber]!='\0';sizeNumber++);
    sizeNumberInt = sizeNumber/SIZECELL;

    if(sizeNumber%SIZECELL!=0){
        sizeNumberInt = sizeNumberInt+1;
        j=0;
    }
    *number = calloc(sizeNumberInt, sizeof(unsigned int));

    for(i=0;i<sizeNumber;i++){
        if((sizeNumber-i)%SIZECELL==0)
            j++;
        (*number)[j]=(*number)[j]*10+(unsigned int)numberS[i]-48;
    }

    return sizeNumberInt;
}

void allocateNumber(unsigned int **number, int size){
    *number = calloc(size, sizeof(unsigned int));
}


void freeNumber(unsigned int **number, int size){
    int i;
    for(i=0; i<size; i++)
        free((*number)+i);
}

int rearrangeNumber(unsigned int **number, int size){
    int i, mult=1, bonus=0;
    int overflow = **number;
    for(i=0;i<SIZECELL;i++)
        mult*=10;

    while(overflow>=mult){
        size++;
        overflow/=mult;
        bonus++;
    }

    *number = realloc(*number, size*sizeof(int));

    for(i=size-bonus-1;i>=0;i--){
        (*number)[i+bonus] = (*number)[i];
    }
    for(i=0;i<bonus;i++)
        (*number)[i] = 0;
    for(i=size-1; i>=1; i--){
        if((*number)[i]>=mult){
            (*number)[i-1] = (*number)[i-1] + ((*number)[i]/mult);
            (*number)[i]=(*number)[i]%mult;
        }
    }

    bonus=0;
    while((*number)[bonus]==0){
        size--;
        bonus++;
    }
    for(i=0;i<size;i++){
        (*number)[i] = (*number)[i+bonus];
    }

    *number = realloc(*number, size*sizeof(int));
    if((*number)[0]>mult)
        size = rearrangeNumber(number, size);

    return size;
}

int addNumber(unsigned int *numberA, int sizeA, unsigned int *numberB, int sizeB, unsigned int **numberC){
    int  sizeC, i;
    sizeC = (sizeA>sizeB) ? sizeA : sizeB;
    allocateNumber(numberC, sizeC);

    for(i=0; i<sizeA&&i<sizeB; i++){
        (*numberC)[sizeC-i-1]=numberA[sizeA-i-1]+numberB[sizeB-i-1];
    }
    if(sizeA > sizeB){
        while(i<sizeC){
            (*numberC)[sizeC-i-1]=numberA[sizeA-i-1];
            i++;
        }
    }
    else{
        while(i<sizeC){
            *numberC[sizeC-i-1]=numberB[sizeB-i-1];
            i++;
        }
    }

    sizeC=rearrangeNumber(numberC,sizeC);
    return sizeC;
}

int mulNumber(unsigned int *numberA, int sizeA, unsigned int *numberB, int sizeB, unsigned int **numberC){
    int sizeC,i, j;
    sizeC = sizeA + sizeB - 1;
    allocateNumber(numberC, sizeC);

    for(i=0; i<sizeA; i++){
        for(j=0; j<sizeB; j++){
            (*numberC)[i+j] += numberA[i] * numberB[j];
        }
    }

    sizeC=rearrangeNumber(numberC,sizeC);
    return sizeC;
}
