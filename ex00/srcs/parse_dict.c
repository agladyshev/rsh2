/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:13:45 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/07 16:23:16 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


#include <stdio.h>

int	get_dict_len(char *filename)
{
	char	buf[1];
	int		bytes;
	int		chars;
	int		file;

	file = open(filename, 0);
	if (file < 0)
		return (0);
	bytes = -1;
	chars = 0;
	while(bytes)
	{
		bytes = read(file, buf, 1);
		if (bytes)
			chars++;
	}
	close(file);
	return (chars);
}

char	*parse_dict_file(char *filename)
{
	int	dict_len;
	char	buf[1];
	int	bytes;
	int	file;
	char	*str;
	int	i;

	dict_len = get_dict_len(filename);
	str = malloc(sizeof(char) * (dict_len + 1));
	file = open(filename, 0);
	if (!dict_len || !str || file < 0)
		return (0);
	bytes = -1;
	i = 0;
	while (bytes)
	{
		bytes = read(file, buf, 1);
		if (bytes)
		{
			str[i] = buf[0];
			i++;
		}
	}	
	str[i] = '\0';
	return (str);
}
