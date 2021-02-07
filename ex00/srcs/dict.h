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

char	*parse_dict_file(char *filename);
char	**ft_split(char *str, char *charset);
int	is_num(char *str);
int	is_dict_valid(char **dict);

#endif


