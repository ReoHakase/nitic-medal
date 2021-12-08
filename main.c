#include <stdio.h>
#include "inc.h"

int main(void){

  struct _country array[ARRLEN];
  fillEmpty(array);
  readCsv(array);

  printf("[メダル順位]\n");
  sort(array, compareMedalRank);
  printTable(array);

  printf("[総獲得数順位]\n");
  sort(array, compareTotal);
  printTable(array);

  printf("[アルファベット順]\n");
  sort(array, compareNameAlphabetically);
  printTable(array);

  return 0;
}