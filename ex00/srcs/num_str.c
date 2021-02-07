/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:00:17 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/07 17:01:48 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

int			is_num_name(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (i);
}

int			count_num_names(char **dict)
{
	int	len;
	int	i;
	int	count;

	i = 0;
	len = 0;
	count = 0;
	while (dict[i])
	{
		len = is_num_name(dict[i]);
		if (len && len <= 3)
			count++;
		i += 2;
	}
	return (count);
}

t_num_str	*get_num_str(char **dict)
{
	t_num_str	*num_str;
	int			count;
	int			i;
	int			j;
	int			len;

	count = count_num_names(dict);
	num_str = malloc(sizeof(t_num_str) * (count + 1));
	i = 0;
	j = 0;
	while (dict[i])
	{
		len = is_num_name(dict[i]);
		if (len && len <= 3)
		{
			num_str[j].key = ft_atoi(dict[i]);
			num_str[j].value = dict[i + 1];
			j++;
		}
		i += 2;
	}
	num_str[j].key = -1;
	num_str[j].value = 0;
	return (num_str);
}
