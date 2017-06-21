#include "utils.h"

int check_dim(int w, int h){
  if(w < 0 || h < 0)
    return -1;
  else return 0;
}

int area(int a, int b){
  return mul(a,b);
}

int perimeter(int a, int b){
  return mul(2, sum(a,b));
}
