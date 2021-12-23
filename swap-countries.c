#include<stdio.h>
#include"inc.h"
void swapCountries(struct _country *a, struct _country *b){
  struct _country temp;
  temp = *b;
  *b = *a;
  *a = temp;
  return;
}