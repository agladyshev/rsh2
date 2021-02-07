#ifndef DICT_H
# define DICT_H

typedef struct	s_num_str
{
	int	key;
	char	*value;
}				t_num_str;

char		*parse_dict_file(char *filename);
char		**ft_split(char *str, char *charset);
char		**get_prefixes(char **dict);
int		is_num(char *str);
int		is_dict_valid(char **dict);
t_num_str	*get_num_str(char **dict);
int		ft_atoi(char *str);
int		is_print_or_line_end(char *str);

#endif
