#include<stdio.h>
#include"inc.h"
void printTable(const struct _country *arrayPointer) {
    int j, k = 1;
    printf("メダル順位        国名    金メダル    銀メダル    銅メダル\n");
    for(int i=0; i<ARRLEN; i++) {
        j = isEmptyCountry(arrayPointer);
        if(j == 1) arrayPointer += 1;
        else {
            printf("%10d%24s%12d%12d%12d\n", k, arrayPointer -> name, arrayPointer -> gold, arrayPointer -> silver, arrayPointer -> bronze);
            k += 1;
            arrayPointer += 1;
        }
    }
}