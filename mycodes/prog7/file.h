
#ifndef FILE_H 
#define FILE_H

FILE* count_records(const char *filename, int *individualCount, int *familyCount);

void read_file(char **indIDs, char **names, char **spouseIDs, char **childIDs, FILE *filePtr);

char* read_indi(char **indIDs, char **names, int *ind_count, char *line, FILE *fp);
char* read_family(char **spouseIDs, char **childIDs, int *fam_count, char *line, FILE *fp);
char* read_other(char *line, FILE * fp);

char* get_ID(char *line);

#endif
