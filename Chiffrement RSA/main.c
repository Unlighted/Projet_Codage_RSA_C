#include <stdio.h>
#include <stdlib.h>
#include "basicFunctions.h"
#include "advancedFunctions.h"

int main()
{
    unsigned int *P,*Q,*N;
    int sizeP,sizeQ,sizeN,i;
    sizeP=getNumber(&P,'P');
    sizeQ=getNumber(&Q,'Q');
    //distributeAll(P, sizeP, *Q);
    //for(i=0;i<sizeP;i++) printf("%u, %u\n",sizeP, P[i]);


    //sizeN=subNumber(P,sizeP,Q,sizeQ,&N);
    sizeN=isModOf(P,sizeP,Q,sizeQ,&N);
    //sizeN=getPrimeNumber(P,sizeP,&N);
    printf("\n");
    for(i=0;i<sizeN;i++) printf("%u\n",N[i]);
    return 0;
}
