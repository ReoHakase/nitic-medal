#include <stdio.h>
#include "inc.h"

int compareMedalRank(const struct _country *left, const struct _country *right){
  if(left -> gold > right -> gold){    //leftの方が大きかったら値はそのまま
    return 0;
  }
  if(left -> gold < right -> gold){
    return 1;
  }
  if(left -> gold == right -> gold){
    if(left -> silver > right -> silver){
      return 0;
    }
    if(left -> silver < right -> silver){
      return 1;
    }
    if(left -> silver == right -> silver){
      if(left -> bronze > right -> bronze){
        return 0;
      }
      if(left -> bronze < right -> bronze){
        return 1;
      }
      if(left -> bronze == right -> bronze){
        return 0;
    }
  }
}
}