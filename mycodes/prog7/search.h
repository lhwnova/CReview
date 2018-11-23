
#ifndef SEARCH_H 
#define SEARCH_H

void find_children(char **indIDs, char **names, char **spouseIDs, char **childIDs, 
	int indCount, int famCount);

int find_name(char **names, int indCount, char inName[80]);
int find_ID(const char *ID, char **IDs, int count);

#endif
