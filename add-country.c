#include<stdio.h>
#include"inc.h"

int addCountry(struct _country *arrayPointer, const struct _country *country) {
    int a;
    for(int i=0; i<ARRLEN; i++) {
        a = isEmptyCountry(arrayPointer);
        if(a == 1) {
            for(int j=0; j<STRLEN; j++) {
                arrayPointer -> name[j] = country -> name[j];
            }
            arrayPointer -> gold = country -> gold;
            arrayPointer -> silver = country -> silver;
            arrayPointer -> bronze = country -> bronze;
            return 1;
        }
        arrayPointer += 1;
    }
    return 0;
}