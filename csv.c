#include <stdio.h>
#include <stdlib.h>
#include "inc.h"

#define CHARSPERLINE 256

extern struct _country emptyCountry;

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
  filePointer = fopen(CSVNAME, "w");
  if(filePointer == NULL) return FILEHANDLEERROR;

  

  if(fclose(filePointer) == EOF){
    return FILEHANDLEERROR;
  }else{
    return 0;
  }
}