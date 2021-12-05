#include <stdio.h>

void swapInts(int *a, int *b){ // 2値の入れ替え
  int initialA = *a;
  *a = *b;
  *b = initialA;
}

void sort(int *arrayPointer, int length, int (*funcPointer)(int, int)){
  // 配列(の先頭)を指すポインタによる配列自身のsizeofは配列全体の大きさを返さない？
  // int length = sizeof *arrayPointer / sizeof(int); // 配列の長さになってほしい
  // printf("Length of arrayPointer: %d, %ld", length, sizeof *arrayPointer);
  for(int i = 0; i < length; i++){
    // printf("head: arrayPointer[%d]: %d\n", i, arrayPointer[i]);
    // 最も右側から順に隣り合う値を入れ替える
    for(int compareTarget = length - 1; compareTarget > i; compareTarget--){
      // printf("compare: arrayPointer[%d]: %d, arrayPointer[%d]: %d\n", compareTarget - 1, arrayPointer[compareTarget - 1], compareTarget, arrayPointer[compareTarget]);
      // 比較用の関数のcompareを使い、それの戻り地に合わせて入れ替え
      if(!(funcPointer(arrayPointer[compareTarget - 1], arrayPointer[compareTarget]))){
        // printf("swap\n");
        swapInts(&arrayPointer[compareTarget], &arrayPointer[compareTarget - 1]);
      }
    }
  }
}

// 入れ替えるときにfalse, そのままのときにtrueを返す関数
// leftが番号の小さい左側の値、rightが番号が大きい右側の値
int compare(int left, int right){
  // printf("比較: %d, %d\n", left, right);
  return left > right;
}

int main(void){

  int array[10] = {4,5,6,1,2,3,7,8,9,10};
  int length = sizeof(array) / sizeof(int); // 配列の長さ
  printf("配列の長さ: %d\n", length);

  sort(array, length, compare);

  for(int i = 0; i < length; i++){
    printf("array[%d]: %d\n", i, array[i]);
  }
  return 0;
}