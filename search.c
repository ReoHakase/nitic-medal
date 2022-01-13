#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "inc.h"

// void search(const struct _country *target, struct _country *result, char *query){

//   int i,j;
//   char lowered[STRLEN];

//   for(i=0; i < ARRLEN; i++){
//     for(j=0; j < STRLEN; j++){
//       lowered[j] = tolower(target[i].name[j]);
//     }
//     if(strstr(lowered[j],query) != NULL){
//       result[i] = target[i];
//     }
//   }
// }


void search(const struct _country *target, struct _country *result, char *query){

  int i,j;
  char lowered[STRLEN];

  for(i=0; i < ARRLEN; i++){
    for(j=0; j < STRLEN; j++){
      lowered[j] = tolower(target[i].name[j]);
    }
    if(strstr(lowered,query) != NULL){
      result[i] = target[i];
    }
  }
}