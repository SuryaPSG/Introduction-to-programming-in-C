#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

int main(int argc, char ** argv) {  
  //WRITE YOUR CODE HERE
  if(argc==1){
    char ** lines=NULL;
    char * curr=NULL;
    size_t sz=0;
    size_t i=0;
    while(getline(&curr,&sz,stdin)>=0){
      lines=realloc(lines,(i+1)*sizeof(*lines));
      lines[i]=curr;
      curr=NULL;
      i++;
    }
    free(curr);
    sortData(lines,i);
    for(int j=0;j<i;j++){
      printf("%s",lines[j]);
      free(lines[j]);
    }
    free(lines);
    return EXIT_SUCCESS;
  }
  if(argc>1){
    for(int k=1;k<argc;k++){
      FILE *f=fopen(argv[k],"r");
      if(f==NULL){
	fprintf(stderr,"No file existed\n");
	return EXIT_FAILURE;
      }
      char ** lines=NULL;
      char * curr=NULL;
      size_t sz=0;
      size_t i=0;
      while(getline(&curr,&sz,f)>=0){
	lines=realloc(lines,(i+1)*sizeof(*lines));
	lines[i]=curr;
	curr=NULL;
	i++;
      }
      free(curr);
      sortData(lines,i);
      for(int j=0;j<i;j++){
	printf("%s",lines[j]);
	free(lines[j]);
      }
      free(lines);
      fclose(f);
    }
  }
  return EXIT_SUCCESS;
}
