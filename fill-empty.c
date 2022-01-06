#include<stdio.h>
#include"inc.h"

void fillEmpty(struct _country *arrayPointer) {
    for(int a=0; a<ARRLEN; a++) {
        for( int i=0; i < STRLEN; i++ ) {
            arrayPointer -> name[i] = '0';
        }
        arrayPointer -> gold = 0;
        arrayPointer -> silver = 0;
        arrayPointer -> bronze = 0;
        arrayPointer += 1;
    }
}