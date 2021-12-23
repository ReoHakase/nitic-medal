#include <stdio.h>
#include "inc.h"

int main(void){

  struct _country array[ARRLEN];
  fillEmpty(array);

  readCsv(array);

  for(int i = 0; i < ARRLEN; i++){
    printf("[%d] name: %s, gold: %d, silver: %d, bronze: %d\n", i, array[i].name, array[i].gold, array[i].silver, array[i].bronze);
  }

  printf("array[3]は空？ %d\n", isEmptyCountry(&array[3]));
  printf("array[60]は空？ %d\n", isEmptyCountry(&array[60]));

  swapCountries(&array[3], &array[60]);

  printf("array[3]とarray[60]を入れ替え後:\n");
  printf("[%d] name: %s, gold: %d, silver: %d, bronze: %d\n", 3, array[3].name, array[3].gold, array[3].silver, array[3].bronze);
  printf("[%d] name: %s, gold: %d, silver: %d, bronze: %d\n", 60, array[60].name, array[60].gold, array[60].silver, array[60].bronze);
  printf("array[3]は空？ %d\n", isEmptyCountry(&array[3]));
  printf("array[60]は空？ %d\n", isEmptyCountry(&array[60]));

  printf("国の個数: %d\n", countCountries(array));

  return 0;
}