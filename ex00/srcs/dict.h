/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:58:49 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/07 16:59:47 by stiffiny         ###   ########.fr       */
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

#endif
