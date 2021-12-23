#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "inc.h"

void sort(struct _country *arrayPointer, const int (*funcPointer)(const struct _country *, const struct _country *)){
  // 配列(の先頭)を指すポインタによる配列自身のsizeofは配列全体の大きさを返さない？
  // int length = sizeof *arrayPointer / sizeof(int); // 配列の長さになってほしい
  // ↑ 渡されるポインタは先頭のアドレスしか含まないから、配列全体の大きさを取得することはできない
  // printf("Length of arrayPointer: %d, %ld", length, sizeof *arrayPointer);
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

// 入れ替えるときにfalse, そのままのときにtrueを返す関数
// (*left)が番号の小さい左側の値、(*right)が番号が大きい右側の値
int compareTotal(const struct _country *left, const struct _country *right){
  return (*left).gold + (*left).silver + (*left).bronze > (*right).gold + (*right).silver + (*right).bronze;
}

int compareMedalRank(const struct _country *left, const struct _country *right){
  // printf("比較: %d, %d\n", (*(*left)), (*right));
  if((*left).gold != (*right).gold){
    return (*left).gold > (*right).gold; // 金メダルの個数が異なるときはそれの大小が順位。同じ場合、vvv
  }else if((*left).silver != (*right).silver){
    return (*left).silver > (*right).silver; // 銀メダルの個数が異なるときはそれの大小が順位。同じ場合、vvv
  }else if((*left).bronze != (*right).bronze){
    return (*left).bronze > (*right).bronze; // 銅メダルの個数が異なるときはそれの大小が順位。同じ場合、vvv
  }else{
    // この場合獲ったメダルの分布が完全に等しいから、同順位となる。したがって、返す値はtrue/falseどちらでもいい
    return 1;
  }
}

int compareName(const struct _country *left, const struct _country *right){
  int minLength;
  if(strlen((*left).name) > strlen((*right).name)){
    minLength = strlen((*left).name);
  }else{
    minLength = strlen((*left).name);
  }
  for(int i = 0; i < minLength; i++){
    // 小文字大文字の違いによる文字コードの差をなくすために小文字にそろえる
    // (*left)と(*right)が異なるとき
    if(tolower((*left).name[i]) != tolower((*right).name[i])){
      // その文字のどちらがアルファベット順で先か返す
      return tolower((*left).name[i]) < tolower((*right).name[i]);
    }
  }
  // 比較できる文字数分比較してそこまですべて等しかったとき、どうする？
  return 1; // そのままにしとく
}

void printTable(const struct _country *arrayPointer){
  printf("\033[4m    %32s %4s %4s %4s   (%5s)\033[0m\n", "国名", "金", "銀", "銅", "合計");
  int row = 1; // 行番号
  for(int i = 0; i < ARRLEN; i++){
    if(isEmptyCountry(&arrayPointer[i]) == 0){
      printf("%2d. %30s \033[33m%3d \033[37m%3d \033[31m%3d   \033[39m(%3d)\n",
        row, 
        arrayPointer[i].name, 
        arrayPointer[i].gold, 
        arrayPointer[i].silver, 
        arrayPointer[i].bronze,
        arrayPointer[i].gold + arrayPointer[i].silver + arrayPointer[i].bronze
      );
      row++;
    }
  }
}
