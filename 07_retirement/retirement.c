#include<stdio.h>
#include<stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

double calc_balance(double initial,double ror,double contribution){
  double val=initial+contribution+(initial*ror);
  return val;
}

void retirement(int startAge,double initial,retire_info working,retire_info retired){
  double cbal=initial;
  int years=startAge/12;
  int months=startAge%12;

  for(int i=0;i<working.months;i++){
    printf("Age %3d month %2d you have $%.2lf\n",years,months,cbal);
    cbal=calc_balance(initial,working.rate_of_return,working.contribution);
    initial=cbal;
    months+=1;
    if(months==12){
      years+=1;
      months=0;
    }
  }
  for(int j=0;j<retired.months;j++){
    printf("Age %3d month %2d you have $%.2lf\n",years,months,cbal);
    cbal=calc_balance(initial,retired.rate_of_return,retired.contribution);
    initial=cbal;
    months+=1;
    if(months==12){
      years+=1;
      months=0;
    }
  }
}
int main(void){
  retire_info working;
  working.months=489;
  working.contribution=1000;
  working.rate_of_return=0.045/12;
  retire_info retired;
  retired.months=384;
  retired.contribution=-4000;
  retired.rate_of_return=0.01/12;
  int age=327;
  double initial=21345;
  retirement(age,initial,working,retired);
  return 0;
}
