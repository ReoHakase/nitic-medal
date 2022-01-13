#include<stdio.h>
#include"inc.h"

int countCountries(struct _country *arrayPointer){
 int i;
 int number=0;
 for(i=0;i<ARRLEN;i++){
  if(isEmptyCountry(&arrayPointer[i])==0){
    number+=1;
  }
}
return number;
}