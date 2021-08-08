#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Letter letter;

struct Letter
{
	char c;
	struct Letter* next;
};

//fonctions complémentaires
letter *new_letter(char c);
void del_lstletter(letter **list);
letter* insert_letter(letter** debut, char c);
char* read_nl(int fd);
char* read_str(int size, letter** debut);
//fonction demandée
char *get_next_line(int fd);

#endif
