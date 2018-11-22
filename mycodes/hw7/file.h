// Author: Huan Wei Li

#ifndef FILE_H
#define FILE_H

FILE *count_records(const char *filename, int *family_count, int *individual_count);

void read_file(char **indiIDs, char **names, char **spousesIDs, char **childIDs, FILE *fp);

char *read_indi(char line[], FILE *fp, int *countind, char **indiIDs, char **names);

char *read_family(char line[], FILE *fp, int *countfam, char **spousesIDs, char **childIDs);

char *read_other(char line[], FILE *fp);

char *get_ID(char line[]);

#endif 
