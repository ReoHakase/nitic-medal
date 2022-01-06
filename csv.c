#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc.h"

#define CHARSPERLINE 256
#define EXPORTEDCSVNAME "exported.csv"

// extern struct _country emptyCountry;

int readCsv(struct _country *arrayPointer){
  FILE *filePointer;
  filePointer = fopen(CSVNAME, "r");
  if(filePointer == NULL) return FILEHANDLEERROR;

  for(int i = 0; i < ARRLEN; i++){
    char currentLine[CHARSPERLINE];
    if(fgets(currentLine, CHARSPERLINE, filePointer) == NULL){
      break;
    }else{
      // Rank,Country,Gold,Silver,Bronze
      int parsedVariables = sscanf(currentLine, "%*d,%[^,],%d,%d,%d", 
        arrayPointer[i].name, 
        &(arrayPointer[i].gold), 
        &(arrayPointer[i].silver), 
        &(arrayPointer[i].bronze)
      );
      // 国名にカンマが含まれていて解析に失敗した時、
      if(parsedVariables < 4){
        sscanf(currentLine, "%*d,\"%[^\"]\",%d,%d,%d", 
          arrayPointer[i].name, 
          &(arrayPointer[i].gold), 
          &(arrayPointer[i].silver), 
          &(arrayPointer[i].bronze)
        );
      }
    }
  }

  if(fclose(filePointer) == EOF){
    return FILEHANDLEERROR;
  }else{
    return 0;
  }
}

int writeCsv(struct _country *arrayPointer){
  FILE *filePointer;
  filePointer = fopen(EXPORTEDCSVNAME, "w");
  if(filePointer == NULL) return FILEHANDLEERROR;

  fprintf(filePointer, "Rank,Country,Gold,Silver,Bronze\n");
  for(int i = 0; i < ARRLEN; i++){
    if(isEmptyCountry(&arrayPointer[i]) == 0){
      char escapedName[STRLEN+2];
      if(strchr(arrayPointer[i].name, ',') == NULL){
        strcpy(escapedName, arrayPointer[i].name);
      }else{
        sprintf(escapedName, "\"%s\"", arrayPointer[i].name);
      }
      fprintf(filePointer, "%d,%s,%d,%d,%d\n", i + 1, escapedName, arrayPointer[i].gold, arrayPointer[i].silver, arrayPointer[i].bronze);
    }
  }

  if(fclose(filePointer) == EOF){
    return FILEHANDLEERROR;
  }else{
    return 0;
  }
}