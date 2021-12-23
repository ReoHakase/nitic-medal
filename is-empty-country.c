#include<stdio.h>
#include"inc.h"

int isEmptyCountry(const struct _country *p) {
    int i = 0;
    if(p -> gold == 0 && p -> silver == 0 && p -> bronze == 0) {
        while( i < STRLEN ) {
            if (p -> name[i] == '0'|| p -> name[i] == '\0') i++;
            else break;
        }
    }
    if(i == 255) return 1;
    else return 0;
}