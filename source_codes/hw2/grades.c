// Author: Sean Davis

#include <stdio.h>

void get_grades(const char *course, int *as, int *bs, int *cs, int *ds, 
  int *fs);
void add_grades(int as, int bs, int cs, int ds, int fs, int *a_total, 
  int *b_total, int *c_total, int *d_total, int *f_total);
void show_totals(int a_total, int b_total, int c_total, int d_total, 
  int f_total);

int main()
{
  int as, a_total = 0, bs, b_total = 0, cs, c_total = 0, ds, d_total = 0, fs, 
    f_total = 0;
  get_grades("ECS 10", &as, &bs, &cs, &ds, &fs);
  add_grades(as, bs, cs, ds, fs, &a_total, &b_total, &c_total, &d_total, 
    &f_total);
  get_grades("ECS 20", &as, &bs, &cs, &ds, &fs);
  add_grades(as, bs, cs, ds, fs, &a_total, &b_total, &c_total, &d_total, 
    &f_total);
  get_grades("ECS 30", &as, &bs, &cs, &ds, &fs);
  add_grades(as, bs, cs, ds, fs, &a_total, &b_total, &c_total, &d_total, 
    &f_total);
    get_grades("ECS 40", &as, &bs, &cs, &ds, &fs);
  add_grades(as, bs, cs, ds, fs, &a_total, &b_total, &c_total, &d_total, 
    &f_total);
  show_totals(a_total, b_total, c_total, d_total, f_total);
  return 0;
} // main()

void get_grades(const char *course, int *as, int *bs, int *cs, int *ds, int *fs)
{
  printf("Please enter the grades for %s in order As Bs Cs Ds Fs: ", course);
  scanf("%d %d %d %d %d", as, bs, cs, ds,fs);
} // get_grades()

void add_grades(int as, int bs, int cs, int ds, int fs, int *a_total, 
  int *b_total, int *c_total, int *d_total, int *f_total)
{
  *a_total += as;
  *b_total += bs;
  *c_total += cs;
  *d_total += ds;
  *f_total += fs;
} // add_grades()
  
  
void show_totals(int a_total, int b_total, int c_total, int d_total, int f_total)
{
  int total = a_total + b_total + c_total + d_total + f_total;
  printf("The percentages were A: %d%%, B: %d%%, C: %d%%, D: %d%%, F: %d%%.\n",
    100 * a_total / total, 100 * b_total / total, 100 * c_total / total,
    100 * d_total / total, 100 * f_total / total);
} // show_totals()
