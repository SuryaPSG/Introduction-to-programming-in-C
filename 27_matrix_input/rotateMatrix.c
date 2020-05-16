#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
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
int main(int argc,char ** argv){
  if(argc!=2){
    fprintf(stderr,"Usage ./file input\n");
    return EXIT_FAILURE;
  }
  FILE *f=fopen(argv[1],"r");
  if(f==NULL){
    fprintf(stderr,"FAILURE0");
    return EXIT_FAILURE;
  }
  char str[12];
  char matrix[10][10];
  int i=0;
  while(fgets(str,12,f)!=NULL){
    if(strchr(str,'\n')==NULL){
    fprintf(stderr,"FALIURE1\n");
      return EXIT_FAILURE;
    }
    for(int j=0;j<10;j++){
      if(str[j]=='\n'){
	fprintf(stderr,"FALIURE2\n");
	return EXIT_FAILURE;
      }
      matrix[i][j]=str[j];
    }
    i++;
  }
  if(i<10){
    fprintf(stderr,"FALIURE3\n");
    return EXIT_FAILURE;
  }
  if(i>10){
    fprintf(stderr,"FALIURE4\n");
    return EXIT_FAILURE;
  }
  rotate(matrix);
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      printf("%c",matrix[i][j]);
    }
    printf("\n");
  }
  if(fclose(f)!=0)
    return EXIT_FAILURE;
  return EXIT_SUCCESS;
}
