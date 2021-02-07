/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <stiffiny@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:10:02 by stiffiny          #+#    #+#             */
/*   Updated: 2021/01/27 16:28:52 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_numbers(char *str, int i)
{
	int numbers;

	numbers = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		numbers++;
		i++;
	}
	return (numbers);
}

int		count_minus_sign(char *str)
{
	int signs;
	int i;

	i = 0;
	signs = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signs++;
		}
		i++;
	}
	return (signs);
}

int		num_multiply_by_position(int num, int count)
{
	int j;

	j = 0;
	while (j < count - 1)
	{
		num *= 10;
		j++;
	}
	return (num);
}

int		ft_atoi(char *str)
{
	int i;
	int signs;
	int res;
	int count;

	res = 0;
	i = 0;
	signs = 0;
	while ((str[i] >= 48 && str[i] <= 57) || str[i] == '\r' || str[i] == ' ' ||
			str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '-' || str[i] == '+')
	{
		signs = (str[i] == '-') ? signs + 1 : signs;
		if (str[i] >= 48 && str[i] <= 57)
		{
			count = count_numbers(str, i);
			res += num_multiply_by_position(str[i] - 48, count);
			count--;
		}
		i++;
	}
	res = (signs % 2 == 1) ? -res : res;
	return (res);
}
