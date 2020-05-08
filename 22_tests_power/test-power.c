#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x,unsigned y);

void run_check(unsigned x,unsigned y,unsigned expected_ans){
  if(power(x,y)==expected_ans)
    return;
  else
    exit(EXIT_FAILURE);
}
int main(void){
  run_check(0,0,1);
  run_check(0,6,0);
  run_check(6,0,1);
  run_check(-6,2,36);
  run_check(-5,3,-125);
  //run_check(2,-1,0.5);
  //run_check(1,-1,1);
  //run_check(2,1,2);
  exit(EXIT_SUCCESS);
}
