#include "get_next_line.h"

letter *new_letter(char c)
{
	letter *new;

	if(!(new = malloc(sizeof(letter))))
		return NULL;
	new->next = NULL;
	new->c = c;
	return new;
}

void del_lstletter(letter **list)
{
	letter *tmp;
	
	if (!list)
		return ;

	while((*list))
	{
		tmp = (*list);
		(*list) = (*list)->next;
		free(tmp);
	}
	free(list);
}

letter* insert_letter(letter** debut, char c)
{
	letter* elem = new_letter(c);
	elem->next = *debut;
	return elem;
}

char* read_nl2(int fd)
{
	if(fd < 0) return NULL;
	int i;
	char buffer[1];
	//letter **debut = malloc(sizeof(letter*));//genius
	letter **debut = malloc(sizeof(letter*));
	*debut = NULL;
	int n;
	char c;

	i = 0;
	//printf("beak 1\n");
	while (i < BUFFER_SIZE)//oubli du cas ou reach \n
	{
		//printf("beak 2\n");
		n = read(fd, buffer, 1);
		if (n == 0 && i==0)
		{
			//printf("beak 3\n");
			free(debut);
			return NULL;
		}
		c = buffer[0];
		if(n > 0 && (c != '\n'))
		{	
			//printf("avant insert\n");
			*debut = insert_letter(debut, c);
			//printf("%c",(*debut)->c);
		}
		else
		{
			
			//printf("problem");
			break;
		}	
		i++;
		//printf("*");
	}
	//printf("\n%d\n", i);
	if (!debut) printf("debut est NULL");
	if (i == 0) return NULL;
	char * str = read_str(i, debut);
	del_lstletter(debut);
	return str;	
}


/*
if fd < 0 return NULL; sinon return tout avec \n se lam trong gnl()

*/

char* read_nl(int fd)
{
	//printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	int i;
	char buffer[1];
	letter **debut;
	int n;
	char *str;

	i = -1;
	n = 0;
	debut = malloc(sizeof(letter*));
	*debut = NULL;
	//printf("beak 1\n");
	while (++i < BUFFER_SIZE)
	{
		//printf("i = %d\n", i);
		n = read(fd, buffer, 1);
		//printf("read return %d\n", n);
		if(n <= 0)
		{
			//printf("cas n <= 0\n");
			if (i == 0)
			{
				//printf("cas i == 0\n");
				del_lstletter(debut);
				return NULL;
			}
			else
			{
				//printf("cas i != 0\n");
				str = read_str(i, debut);
				del_lstletter(debut);
				return str;
			}
		}

		if(buffer[0] == '\n')
		{
			//printf("cas n <= 0\n");
			str = read_str(i, debut);
			del_lstletter(debut);
			return str;
		}
		//printf("ca passe\n");
		*debut = insert_letter(debut, buffer[0]);
	}
	//printf("buffer = %c\n", buffer[0] );
	str = read_str(i, debut);
	del_lstletter(debut);
	//printf("string = %s", str);
	return str;	
}

char* read_str(int size, letter** debut)
{
	//printf("read_str\n");
	char *str= malloc(sizeof(char) * (size + 2));
	letter *tmp = *debut;
	str[size] = '\n';
	str[size + 1] = '\0';
	while (size > 0 && tmp)
	{
		//printf("tmp-c = %c \n",tmp->c);
		str[size - 1] = tmp->c;
		tmp = tmp->next;
		size--;
	}
	return str;
}


