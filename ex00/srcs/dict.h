#ifndef DICT_H
# define DICT_H


//remove this later
#include <stdio.h>



typedef struct	s_place_value
{
	int		place;
	char	*value;
}				t_place_value;

typedef struct	s_one_two_digits
{
	char	*key;
	char	*value;
}				t_one_two_digits;

void	parse_dict_file(char *filename);

#endif
