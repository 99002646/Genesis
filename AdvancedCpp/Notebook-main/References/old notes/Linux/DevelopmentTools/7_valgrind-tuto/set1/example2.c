#include<stdio.h>
#include<string.h>
int main(int argc, char* argv[]) {
  int *parr;
  int len=10;
    int sum;
  if(argc > 1)
    len = strtoul(argv[1],NULL,10);
  parr = malloc(len * sizeof(int));
  srand(time(0));
  for(int i=0;i<len;i++)
    parr[i] = rand()%100;
  for(int i=0;i<len;i++)
    sum += parr[i];
  free(parr);
  parr[5] = 50;     
  printf("Thank You\n");
  return 0;
}
