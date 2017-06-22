#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "utils.h"
#include "rect.h"
#include "usage.h"

int main(int argc, char **argv){
  system("rm -f wynik.txt");
  int option = 0;
  int a = -1, p = -1, width = -1, height = -1;
  char buf[128];
  while ((option = getopt(argc, argv, "apw:h:")) != -1){
    switch(option){
    case 'a' :
      a = 0;
      break;
    case 'p' :
      p = 0;
      break;
    case 'w' :
      width = atoi(optarg);
      break;
    case 'h' :
      height = atoi(optarg);
      break;
    default:
      print_usage();
      exit(EXIT_FAILURE);
    }
  }

  //printf("ar: %d\nper: %d\nwidth: %d\nheight: %d\n", a, p, width, height);

  if (check_dim(width,height)==-1){
    print_usage();
    exit(EXIT_FAILURE);
  }
  if(a == 0){
    a = area(width, height);
    //printf("Area: %d\n", a);
    snprintf(buf, sizeof(buf), "echo 'Area: %d' >> wynik.txt", a);
    system(buf);
  }
  if(p == 0){
    p = perimeter(width, height);
    //printf("Perimeter: %d\n", p);
    snprintf(buf, sizeof(buf), "echo 'Perimeter: %d' >> wynik.txt", p);
    system(buf);
  }
  return 0;
}
