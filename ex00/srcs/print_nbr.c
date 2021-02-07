/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:51:59 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/07 20:42:19 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <unistd.h>

int		print_one(int nbr, t_num_str *num_dict, int len)
{
	char	*val;

	val = get_nbr_name(nbr, num_dict);
	if (val)
		trim_putstr(val, len == 3);
	else
		return (1);
	return (0);
}

int		print_two(int nbr, t_num_str *num_dict, int len)
{
	int		cur;
	char	*val;
	int		is_error;

	is_error = 0;
	if (nbr < 20)
	{
		val = get_nbr_name(nbr, num_dict);
		if (val)
			trim_putstr(val, 0);
		else
			return (1);
	}
	else
	{
		cur = nbr / 10;
		val = get_nbr_name(cur * 10, num_dict);
		if (val)
			trim_putstr(val, 0);
		else
			return (1);
		is_error = print_one(nbr - cur * 10, num_dict, len);
	}
	return (is_error);
}

int		print_three(int nbr, t_num_str *num_dict, int len)
{
	int		cur;
	char	*val;
	int		is_error;

	is_error = 0;
	cur = nbr / 100;
	val = get_nbr_name(cur, num_dict);
	if (val)
		trim_putstr(val, 0);
	else
		return (1);
	val = get_nbr_name(100, num_dict);
	if (val)
		trim_putstr(val, 0);
	else
		return (1);
	is_error = print_two(nbr - cur * 100, num_dict, len);
	return (is_error);
}

int		print_nbr_by_position(int nbr, t_num_str *num_dict, int len)
{
	int is_error;

	is_error = 0;
	if (nbr / 100 > 0)
		is_error = print_three(nbr, num_dict, len);
	else if (nbr / 10 > 0)
		is_error = print_two(nbr, num_dict, len);
	else if ((nbr > 0) || (nbr == 0 && len == 1))
		is_error = print_one(nbr, num_dict, len);
	return (is_error);
}

int		print_nbr_words(char *str, char **prefixes, t_num_str *num_dict)
{
	int len;
	int end;
	int nbr;
	int is_error;

	is_error = 0;
	len = ft_strlen(str);
	if (check_if_too_big(len, prefixes))
	{
		write(2, "Dict Error\n", 11);
		return (1);
	}
	while (*str)
	{
		end = (len % 3) ? len % 3 : 3;
		nbr = get_nbr_str_start_end(str, 0, end);
		is_error = print_nbr_by_position(nbr, num_dict, len);
		str += end;
		len -= end;
		if (len >= 3 && nbr)
			trim_putstr(prefixes[len], 0);
	}
	write(1, "\n", 1);
	return (is_error);
}
