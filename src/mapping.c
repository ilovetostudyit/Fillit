/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:08:49 by ehaggon           #+#    #+#             */
/*   Updated: 2019/02/23 15:28:34 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		number_of_hash(char *str)
{
	int index;
	int j;

	index = 0;
	j = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '#')
			j++;
		index++;
	}
	return (j);
}

int		sqrt_hash(int hash)
{
	int a;

	a = 0;
	while ((a * a) < hash)
	{
		a++;
	}
	return (a);
}

char	*coloring(char *str)
{
	int index;
	int j;
	int m;

	index = 0;
	j = 0;
	m = 'A';
	while (str[index] != '\0')
	{
		if (j < 4)
		{
			if (str[index] == '#')
			{
				str[index] = m;
				j++;
			}
		}
		else
		{
			j = 0;
			m++;
		}
		index++;
	}
	return (str);
}

char	*createmapp(int a)
{
	char	*map;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	map = (char *)malloc(sizeof(char) * ((a + 1) * (a) + 1));
	while (i < ((a + 1) * a))
	{
		while (i < ((a + 1) * a) && cnt < a)
		{
			map[i] = '.';
			cnt++;
			i++;
		}
		map[i] = '\n';
		cnt = 0;
		i++;
	}
	map[i] = '\0';
	return (map);
}

char	*createorder(int a)
{
	char	*str;
	int		i;
	char	chr;

	i = 0;
	chr = 'A';
	if ((str = (char *)malloc(sizeof(char) * (a + 1))) == 0)
		return (NULL);
	while (i < (a))
	{
		str[i] = chr;
		i++;
		chr++;
	}
	str[i] = '\0';
	return (str);
}
