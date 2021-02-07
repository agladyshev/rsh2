/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefixes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:09:53 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/07 18:21:19 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

int		is_prefix(char *str)
{
	int i;

	i = 1;
	if (str[0] == '-')
		return (0);
	if (str[0] == '+')
		str++;
	if (str[0] != '1')
		return (0);
	while (str[i] == '0')
		i++;
	if (i < 2)
		return (0);
	return (i);
}

void	set_arr_to_empty_str(char ***arr, int len)
{
	int		i;
	char	*empty;

	i = 0;
	empty = malloc(sizeof(char));
	empty[0] = '\0';
	while (i < len)
	{
		(*arr)[i] = empty;
		i++;
	}
}

int		count_prefixes(char **dict)
{
	int	max;
	int	count;
	int	i;

	i = 0;
	max = 0;
	while (dict[i])
	{
		count = is_prefix(dict[i]);
		if (count > 3)
			if (count > max)
				max = count;
		i += 2;
	}
	return (max);
}

char	**get_prefixes(char **dict)
{
	char	**prefixes;
	int		max;
	int		count;
	int		i;

	max = count_prefixes(dict);
	prefixes = malloc(sizeof(char *) * (max + 1));
	set_arr_to_empty_str(&prefixes, max);
	i = 0;
	while (dict[i])
	{
		count = is_prefix(dict[i]);
		if (count > 3)
		{
			prefixes[count - 1] = dict[i + 1];
		}
		i += 2;
	}
	prefixes[max] = 0;
	return (prefixes);
}
