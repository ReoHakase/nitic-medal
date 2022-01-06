#include<stdio.h>
#include"inc.h"
void printTable(const struct _country *arrayPointer) {
    int j;
    printf("メダル順位        国名    金メダル    銀メダル    銅メダル\n");
    for(int i=0; i<ARRLEN; i++) {
        j = isEmptyCountry(arrayPointer);
        if(j == 1) break;
        else {
            printf("%10d%11s%12d%12d%12d\n", i + 1, arrayPointer -> name, arrayPointer -> gold, arrayPointer -> silver, arrayPointer -> bronze);
            arrayPointer += 1;
        }
    }
}
