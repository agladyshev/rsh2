/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:56:51 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/06 17:54:52 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int		main(int argc, char **argv)
{
	int		is_error;
	char	*dict_str;

	//dict_str is file as string without spaces
	is_error = 0;
	
	if (argc < 2)
		return (1);
	else
		dict_str = (argc == 2) ? parse_dict_file(argv[1]) : parse_dict_file(argv[1]);
	
	return (is_error);
}
