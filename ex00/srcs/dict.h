/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:58:49 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/07 20:41:27 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

typedef struct	s_num_str
{
	int			key;
	char		*value;
}				t_num_str;

char			*parse_dict_file(char *filename);
char			**ft_split(char *str, char *charset);
char			**get_prefixes(char **dict);
int				is_num(char *str);
int				is_dict_valid(char **dict);
t_num_str		*get_num_str(char **dict);
int				ft_atoi(char *str);
int				is_print_or_line_end(char *str);
int				ft_strlen(char *str);
int				print_nbr_words(char *str,
				char **prefixes, t_num_str *num_dict);
void			trim_putstr(char *str, int end);
char			*get_nbr_name(int nbr, t_num_str *num_dict);
int				check_if_too_big(int len, char **prefixes);
int				get_nbr_str_start_end(char *str,
				int start, int end);
#endif
