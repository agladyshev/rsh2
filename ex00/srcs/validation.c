#include <stdio.h>

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
	while(dict[i] != 0)
	{
		if (i % 2 == 0 && !is_num(dict[i]))
			return (0);
		i++;
	}
	if (i < 41 * 2)
		return (0);
	return (1);
}
