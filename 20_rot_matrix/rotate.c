#include<stdio.h>
#include<stdlib.h>

void rotate(char matrix[10][10]){
  char dup[10][10];
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      dup[i][j]=matrix[i][j];
    }
  }
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      matrix[i][j]=dup[9-j][i];
    }
  }
}
