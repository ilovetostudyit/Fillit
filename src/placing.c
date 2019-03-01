/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:37:11 by ehaggon           #+#    #+#             */
/*   Updated: 2019/03/01 17:50:23 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		placing_figure(char *str, char *map, char a, int start)
{
	int mapcntr;
	int hashcntr;
	int countbf;
	int zero;

	mapcntr = 0;
	hashcntr = 0;
	countbf = countbefore(str, firstelement(str, a));
	mapcntr = firstelement(str, a);
	while (hashcntr < 4 && str[mapcntr] != '\0')
	{
		zero = start + countbefore(str, mapcntr) - countbf;
		if (str[mapcntr] == a)
		{
			if (placing_figure_help(map, zero, a) == 0)
				return (0);
			hashcntr++;
		}
		if (str[mapcntr] == '\n')
			start = start + get_size(map) + 1;
		mapcntr++;
	}
	if (hashcntr < 4)
		return (0);
	return (1);
}

int		find_answer(char *str, char *map, char *order, int index)
{
	int		start;
	char	*copy_map;

	index++;
	if (order[index] == '\0')
	{
		ft_putstr(map);
		return (1);
	}
	copy_map = ft_strnew((get_size(map) * (get_size(map) + 1)));
	ft_strcpy(copy_map, map);
	start = 0;
	while (copy_map[start])
	{
		if (placing_figure(str, copy_map, order[index], start))
			if (find_answer(str, copy_map, order, index))
			{
				free(copy_map);
				return (1);
			}
		ft_strcpy(copy_map, map);
		start++;
	}
	free(copy_map);
	return (0);
}

int		order_size(char *order)
{
	int i;

	i = 0;
	while (order[i] != '\0')
		i++;
	return (i);
}

int		firstelement(char *str, char a)
{
	int cntr;

	cntr = 0;
	while (str[cntr] != '\0')
	{
		if (str[cntr] == a)
			return (cntr);
		cntr++;
	}
	return (0);
}

int		countbefore(char *str, int cntr)
{
	int cntbef;

	cntbef = 0;
	while (str[cntr] != '\n')
	{
		cntr++;
		cntbef++;
	}
	return (4 - cntbef);
}
