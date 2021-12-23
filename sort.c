#include <stdio.h>
#include "inc.h"

void sort(struct _country *arrayPointer, const int (*funcPointer)(const struct _country *, const struct _country *)){
  for(int i = 0; i < ARRLEN; i++){
    // 最も右側から順に隣り合う値を比較して、その結果に応じて入れ替える
    for(int compareTarget = ARRLEN - 1; compareTarget > i; compareTarget--){
      // 比較用の関数のcompareを使い、それの戻り地に合わせて入れ替え
      if(!(funcPointer(&arrayPointer[compareTarget - 1], &arrayPointer[compareTarget]))){
        swapCountries(&arrayPointer[compareTarget], &arrayPointer[compareTarget - 1]);
      }
    }
  }
}
