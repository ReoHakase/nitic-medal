#include <stdio.h>
#include <string.h>
#include "inc.h"

struct _country emptyCountry = {
  {0}, 0, 0, 0
};

int isEmptyCountry(const struct _country *country){
  return (
    strcmp((*country).name, emptyCountry.name) == 0 &&
    (*country).gold == emptyCountry.gold &&
    (*country).silver == emptyCountry.silver &&
    (*country).bronze == emptyCountry.bronze
  );
}

void fillEmpty(struct _country *arrayPointer){
  for(int i = 0; i < ARRLEN; i++){
    arrayPointer[i] = emptyCountry;
  }
}

void swapCountries(struct _country *a, struct _country *b){ // 2値の入れ替え
  struct _country initialA = *a;
  *a = *b;
  *b = initialA;
}