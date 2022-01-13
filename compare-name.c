#include<stdio.h>
#include<ctype.h>
#include"inc.h"
#include<string.h>
int compareName(const struct _country *left, const struct _country *right){
    for(int i=0;i< strlen(left -> name) && i< strlen(right -> name);i++){
    if(tolower(left -> name[i]) < tolower(right -> name[i])){
       return 1;
      }
    if(tolower(left -> name[i]) > tolower(right -> name[i])){
       return 0;
      }
  }
    return 1;
}