#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * array, size_t n){
  if(n==0 || array==NULL){
    return 0;
  }
  int max=1;
  int cmax=1;
  for(int i=1;i<n;i++){
    if(array[i]>array[i-1]){
      cmax+=1;
    }
    else{
      if(cmax>max){
	max=cmax;
      }
      cmax=1;
    }
  }
  if(cmax>max)
    max=cmax;
  return max;
}
