// Author: Sean Davis

#ifndef FILE_H
#define	FILE_H

FILE* count_records(const char *filename, int *individual_count, 
  int *family_count);
char* get_ID(char *line);
void read_file(char **indiIDs, char **names, char **spousesIDs, char **childIDs, 
  FILE *fp);

char* read_other(char *line, FILE *fp);
char* read_indi(char **indiIDs, char **names, int *individual_count, char *line,
  FILE *fp);
char* read_familyi(char **spousesIDs, char **childIDs, int *family_count, 
  char *line, FILE *fp);

#endif	

