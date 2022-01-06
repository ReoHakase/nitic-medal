#include<stdio.h>
#include<string.h>

#include"inc.h"
int compareName(const struct _country *left, const struct _country *right){
  for(int i=0;i< strlen(left -> name) && i< strlen(right -> name);i++){
    if(left -> name[i] < right -> name[i]){
       return 1;
      }
    if(left -> name[i] > right -> name[i]){
       return 0;
      }
  }
    return 1;
 }