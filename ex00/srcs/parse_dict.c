/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:13:45 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/07 17:08:32 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		get_dict_len(char *filename)
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
	while (bytes)
	{
		bytes = read(file, buf, 1);
		if (bytes)
			chars++;
	}
	close(file);
	return (chars);
}

char	*create_str_size_of(char *filename)
{
	int		filesize;
	char	*str;

	filesize = get_dict_len(filename);
	str = malloc(sizeof(char) * (filesize + 1));
	return (str);
}

char	*parse_dict_file(char *filename)
{
	char	buf[1];
	int		bytes;
	int		file;
	char	*str;
	int		i;

	str = create_str_size_of(filename);
	file = open(filename, 0);
	if (!str || file < 0)
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
