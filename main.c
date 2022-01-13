#include <stdio.h>
#include "inc.h"

int main(void){

  struct _country array[ARRLEN];
  fillEmpty(array);
  int selection = 0;
  while(1){
    printf("\n\n\n");
    printf("--- 読み込まれた国の数: %d ---\n", countCountries(array));
    printf("行う動作を番号で入力してください\n");
    printf("1: CSVファイルから読み込み\n");
    printf("2: CSVファイルへ書き込み\n");
    printf("3: メダル順位順に一覧表示\n");
    printf("4: 総獲得数順に一覧表示\n");
    printf("5: アルファベット順に一覧表示\n");
    printf("6: 国を検索\n");
    printf("7: 国を追加\n");
    // printf("%p\n", array);

    printf("> ");
    scanf("%d", &selection);
    printf("\n");

    struct _country newCountry;
    int result;
    char filename[STRLEN];
    switch(selection){

      case 1: // CSVファイルからよみこみ
        printf("読み込みたいファイルの名前を入力してください\n> ");
        scanf("%s", filename);
        result = readCsv(array, filename);
        switch(result){
          case 0:
            printf("ファイルから読み込みました\n");
            break;
          case FILEHANDLEERROR:
          default:
            printf("ファイルが存在しないか名前が間違っています\n");
            break;
        }
        break;

      case 2: // CSVファイルへ書き込み
        printf("書き込みたいファイルの名前を入力してください\n> ");
        scanf("%s", filename);
        result = writeCsv(array, filename);
        switch(result){
          case 0:
            printf("ファイルへ書き込みました\n");
            break;
          case FILEHANDLEERROR:
          default:
            printf("ファイルが存在しないか名前が間違っています\n");
            break;
        }
        break;
      
      case 3: // メダル順位順
        sort(array, compareMedalRank);
        printTable(array);
        break;
      case 4: // 合計順
        sort(array, compareTotal);
        printTable(array);
        break;
      case 5: // アルファベット順
        sort(array, compareName);
        printTable(array);
        break;
      case 6: // 検索
        printf("検索名を入力してください\n> ");
        char query[STRLEN];
        scanf("%s", query);
        struct _country filteredArray[ARRLEN];
        fillEmpty(filteredArray);
        search(array, filteredArray, query);
        printTable(filteredArray);
        break;
      case 7: // 追加
        printf("追加したい国の名前を入力してください\n> ");
        scanf("%s", newCountry.name);
        printf("追加したい国の金メダルの数を入力してください\n> ");
        scanf("%d", &(newCountry.gold));
        printf("追加したい国の銀メダルの数を入力してください\n> ");
        scanf("%d", &(newCountry.silver));
        printf("追加したい国の銅メダルの数を入力してください\n> ");
        scanf("%d", &(newCountry.bronze));
        addCountry(array, &newCountry);
        // printf("国名%s, メダル数%d,%d,%d");
        break;
      default:
        printf("上記に当てはまる番号を入力してください\n");
        break;
    }
  }

  return 0;
}