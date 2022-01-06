#include<stdio.h>
#include"inc.h"

int compareTotal(const struct _country *left, const struct _country *right) {
    int a, b;
    a = left -> gold + left -> silver + left -> bronze;
    b = right -> gold + right -> silver + right -> bronze;
    return a > b;
}