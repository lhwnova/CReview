//pointer  and printing string


#include <stdio.h>

void get_grade(int *agrade, int *bgrade, int *cgrade, int *dgrade, int *fgrade, const char *course);
void show_total(int agrade, int bgrade, int cgrade, int dgrade, int fgrade);

int main(){

  int as = 0, bs = 0, cs = 0, ds = 0, fs = 0;

  get_grade(&as, &bs, &cs, &ds, &fs, "ECS 10");
  get_grade(&as, &bs, &cs, &ds, &fs, "ECS 20");
  get_grade(&as, &bs, &cs, &ds, &fs, "ECS 30");
  get_grade(&as, &bs, &cs, &ds, &fs, "ECS 40");
  
  show_total(as, bs, cs, ds, fs);
  
  return 0; 
}



void get_grade(int *agrade, int *bgrade, int *cgrade, int *dgrade, int *fgrade, const char *course){

  int a, b, c, d, f; 

  printf("Please enter the grade for %s in order As Bs Cs Ds Fs: ", course);
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &f);

  *agrade = *agrade + a;
  *bgrade = *bgrade + b;
  *cgrade = *cgrade + c;
  *dgrade = *dgrade + d;
  *fgrade = *fgrade + f;
}


void show_total(int agrade, int bgrade, int cgrade, int dgrade, int fgrade){

  int totalGrade = agrade + bgrade + cgrade + dgrade + fgrade;

  printf("The percentage were A: %d%% B: %d%% C: %d%% D: %d%% F: %d%% \n", (100*agrade/totalGrade), 
  	(100*bgrade/totalGrade), (100*cgrade/totalGrade), (100*dgrade/totalGrade), (100*fgrade/totalGrade));


}
