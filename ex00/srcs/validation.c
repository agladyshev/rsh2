/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:13:42 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/07 18:58:54 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_num(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	is_dict_valid(char **dict)
{
	int i;

	i = 0;
	while (dict[i] != 0)
		i++;
	if ((i < 41 * 2) || (i % 2 != 0))
		return (0);
	return (1);
}

int	is_print_or_line_end(char *str)
{
	while (*str)
	{
		if (*str > 31 || *str == 10)
			str++;
		else
		{
			return (0);
		}
	}
	return (1);
}
