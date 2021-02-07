/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:56:51 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/07 20:44:28 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		is_input_valid(char *str)
{
	while (*str)
	{
		if (!(*str <= '9' && *str >= '0'))
				return (0);
		str++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int			is_error;
	char		*dict_str;
	char		**dict_arr;
	char		**prefixes;
	char		*input;
	t_num_str	*num_str;

	is_error = 0;
	if (argc < 2)
		return (1);
	else
		dict_str = (argc == 3) ? parse_dict_file(argv[1]) : parse_dict_file("numbers.dict.txt");
	if (!dict_str || !is_print_or_line_end(dict_str))
	{
		write(2, "Dict Error\n", 11);
		return (1);
	}
	dict_arr = ft_split(dict_str, ":\n");
	free(dict_str);
	if (!(is_dict_valid(dict_arr)))
	{
		write(2, "Dict Error\n", 11);
		return (1);
	}
	prefixes = get_prefixes(dict_arr);
	num_str = get_num_str(dict_arr);
	input = (argc == 3) ? argv[2] : argv[1];
	if (!is_input_valid(input))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	is_error = print_nbr_words(input, prefixes, num_str);
	if (is_error)
		write(2, "Dict Error\n", 11);
	free(dict_arr);
	return (is_error);
}
