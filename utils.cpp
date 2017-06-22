#include <stdio.h>

float sum(float a, float b){
  return a+b;
}

float sub(float a, float b){
  return a-b;
}

float mul(float a, float b){
  return a*b;
}

float div(float a, float b){
  if(b==0){
    printf("Division by 0");
    return -1;
  }
  else
    return a/b;
}
