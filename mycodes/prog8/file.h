

#ifndef FILE_H
#define FILE_H

#include "main.h"

FILE* count_records(const char *filename, int *individual_count,
  int *family_count);

void read_file(FILE *fptr, Family *families, Individual *individuals);

char* get_ID(char *line);
char* read_other(char *line, FILE *fp);
char* read_indi(Individual *individuals, int *individual_count, char *line, FILE *fp);
char* read_family(Family *families, int *family_count, char *line, FILE *fp);

void add_child(char *line, Family *families);

#endif