// Author: Huan Wei Li 

#ifndef SEARCH_H
#define SEARCH_H

void find_children(char **indiIDs, char **names, char **spousesIDs, char **childIDs, int individual_count, int family_count);

int find_name(char inname[], char **names, int individual_count);

int find_ID(char **spousesIDs, char **indiIDs, int family_count,
  int index); 

void print_out(char inname[], char **indiIds, char **name, int index,
  char **childIds, int countind); 

#endif
