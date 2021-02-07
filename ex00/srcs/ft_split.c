/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 20:40:06 by stiffiny          #+#    #+#             */
/*   Updated: 2021/01/29 20:50:15 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_in_set(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int i;
	int new_word;
	int count;

	count = 0;
	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (is_in_set(str[i], charset))
		{
			new_word = 1;
		}
		else if (new_word)
		{
			new_word = 0;
			count++;
		}
		i++;
	}
	return (count);
}

char	*get_word_at_i(char *str, char *charset, int *i)
{
	int		len;
	int		new_word;
	int		j;
	char	*ptr;

	len = 0;
	new_word = 1;
	j = 0;
	while (str[*i] != '\0')
	{
		new_word = (is_in_set(str[*i], charset)) ? 1 : 0;
		len = (is_in_set(str[*i], charset)) ? len : len + 1;
		if (new_word && len)
			break ;
		*i = *i + 1;
	}
	ptr = malloc(sizeof(char) * len + 1);
	while (j < len)
	{
		ptr[j] = str[*i - len + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	**ft_split(char *str, char *charset)
{
	int		count;
	char	**arr;
	int		c;
	int		i;

	arr = 0;
	count = count_words(str, charset);
	arr = malloc(sizeof(str) * count + 1);
	arr[count] = 0;
	c = 0;
	i = 0;
	while (c < count)
	{
		arr[c] = get_word_at_i(str, charset, &i);
		c++;
	}
	return (arr);
}
