/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:56:51 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/06 17:54:52 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		is_error;
	char		*dict_str;
	char		**dict_arr;
	char		**prefixes;
	t_num_str	*num_str;

	is_error = 0;
	if (argc < 2)
		return (1);
	else
		dict_str = (argc == 3) ? parse_dict_file(argv[1]) : parse_dict_file("numbers.dict.txt");
	if (!dict_str)
	{
		write(2, "Dict Error\n", 11);
		return (1);
	}
	if (!is_print_or_line_end(dict_str))
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
	int i = 0;
	while (prefixes[i])
	{
		printf("prefixes[%d] = \"%s\"\n", i, prefixes[i]);
		i++;
	}
	num_str = get_num_str(dict_arr);
	int j = 0;
	while (num_str[j].key != -1)
	{
		printf("Key: %d | Value: %s\n", num_str[j].key, num_str[j].value);
		j++;
	}
	free(dict_arr);

	return (is_error);
}
