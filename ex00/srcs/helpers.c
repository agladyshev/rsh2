/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:59:37 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/07 20:41:37 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	trim_putstr(char *str, int end)
{
	while (*str == ' ')
	{
		str++;
	}
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	if (!end)
		write(1, " ", 1);
}

char	*get_nbr_name(int nbr, t_num_str *num_dict)
{
	while (num_dict->key != -1)
	{
		if (num_dict->key == nbr)
			return (num_dict->value);
		num_dict++;
	}
	return (0);
}

int		check_if_too_big(int len, char **prefixes)
{
	int i;

	i = 0;
	while (prefixes[i] != 0)
		i++;
	if (len - i > 2)
		return (1);
	return (0);
}

int		get_nbr_str_start_end(char *str, int start, int end)
{
	char	buf[3];
	int		i;
	int		nbr;

	i = 0;
	while (end - i > start)
	{
		buf[i] = str[start + i];
		i++;
	}
	nbr = ft_atoi(buf);
	return (nbr);
}
