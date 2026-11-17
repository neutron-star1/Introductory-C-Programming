#include <stdlib.h>
#include <stdio.h>

typedef struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
}retire_info;

void retirement (int startAge,   //in months
		 double initial, //initial savings in dollars
                 retire_info working, //info about working
		 retire_info retired) //info about being retired
{
  double  cur_sav = initial;
  int total_months = startAge;
  int old_year = 0;
  int old_month = 0;
  for(int i = 0;i < working.months; ++i){
    old_year = total_months/12;
    old_month = total_months%12;
    printf("Age %3d month %2d you have $%.2lf\n",old_year,old_month,cur_sav);   
    cur_sav = cur_sav *(1+working.rate_of_return / 12) + working.contribution;    
    total_months++;
  }
  for(int i = 0;i < retired.months; ++i){
    old_year = total_months/12;
    old_month = total_months%12;
    printf("Age %3d month %2d you have $%.2lf\n",old_year,old_month,cur_sav);    
    cur_sav = cur_sav *(1+retired.rate_of_return / 12) + retired.contribution;
    total_months++;
  }
}

int main(){
  retire_info working = {489,1000,0.045};
  retire_info retired = {384,-4000,0.01};
  retirement(327,21345,working,retired);
  return 0;
}
