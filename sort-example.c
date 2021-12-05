#include <stdio.h>

int swapInts(int *a, int *b){ // 2値の入れ替え
  int initialA = *a;
  *a = *b;
  *b = initialA;
}


// 入れ替えるときにfalse, そのままのときにtrueを返す関数
// leftが番号の小さい左側の値、rightが番号が大きい右側の値
int compare(int left, int right){
  return left < right;
}

int main(void){
  int array[10] = {4,5,6,1,2,3,7,8,9,0};
  // char nameArray[16][10] = {}
  int length = sizeof(array) / sizeof(int); // 配列の長さ
  for(int i = 0; i < length; i++){
    // 最も右側から順に隣り合う値を入れ替える
    for(int compareTarget = length - 1; compareTarget > i; compareTarget--){

      // 左側の要素が、右側の要素よりも大きいときは、何もしない
      // if(array[compareTarget - 1] > array[compareTarget]);
      // 左側の要素が、右側の要素よりも小さいときは、入れ替える
      // if(array[compareTarget - 1] < array[compareTarget]) swapInts(&array[compareTarget], &array[compareTarget - 1]);
      
      // 比較用の関数のcompareを使い、それの戻り地に合わせて入れ替え
      if(!compare(array[compareTarget - 1], array[compareTarget])) swapInts(&array[compareTarget], &array[compareTarget - 1]);
      // 結果、より大きいほうが左側に出てくる
    }

  }

  // swapInts(&elements[0], &elements[1]);
  printf("配列の長さ: %d\n", length);
  for(int i = 0; i < length; i++){
    printf("array[%d]: %d\n", i, array[i]);
  }
  // printf("%d,%d,%d\n", elements[0], elements[1], length);
  return 0;
}