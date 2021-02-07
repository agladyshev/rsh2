/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:13:45 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/06 17:53:01 by stiffiny         ###   ########.fr       */
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
	
	if (!file)
		return (0);
	//error handling
	bytes = -1;
	chars = 0;
	while(bytes)
	{
		bytes = read(file, buf, 1);
		if (bytes && buf[0] != ' ')
			chars++;
	}
	close(file);
	printf("Chars: %d\n", chars);
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
	if (!str)
		return (str);
	// couldn't allocate memory error	
	
	file = open(filename, 0);
	if (!file)
		return (0);
	//error handling
	
	bytes = -1;
	i = 0;
	while (bytes)
	{
		bytes = read(file, buf, 1);
		//printf("Bytes: %d, i: %d, buf: %s\n", bytes, i, buf);
		if (buf[0] != ' ' && bytes)
		{
			str[i] = buf[0];
			i++;
		}
	}	
	printf("Is i = len ? %d %d\n", i,  dict_len);
	str[i] = '\0';

	return (str);
}
