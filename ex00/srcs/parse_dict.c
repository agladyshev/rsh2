/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:13:45 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/06 16:44:56 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <fcntl.h>
#include <unistd.h>

void	parse_dict_file(char *filename)
{
	char	buf[1];
	int		bytes;
	int		chars;
	int		keys;
	int		file;

	file = open(filename, 0);
	
	if (!file)
		return ;
	//error handling
	bytes = -1;
	chars = 0;
	keys = 0;
	while(bytes)
	{
		bytes = read(file, buf, 1);
		if (buf[0] != ' ')
			chars++;
		if (buf[0] == ':')
			keys++;
	}
	close(file);
	printf("Chars: %d | Keys: %d\n", chars, keys);
}
