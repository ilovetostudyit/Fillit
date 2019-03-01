/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver12.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:48:34 by ehaggon           #+#    #+#             */
/*   Updated: 2019/03/01 17:42:02 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		cut_figure(char *str)
{
	int		i;
	int		number_of_figure;
	char	*map;
	char	*order;

	if (validtetriminos2(str) != 1 || validtetriminos4(str) != 1
			|| validtetriminos5(str) != 1)
		return (0);
	i = sqrt_hash(number_of_hash(str));
	number_of_figure = number_of_hash(str) / 4;
	order = createorder(number_of_figure);
	str = coloring(str);
	map = createmapp(i);
	while (find_answer(str, map, order, -1) != 1)
	{
		free(map);
		i = i + 1;
		map = createmapp(i);
	}
	if (order)
		free(order);
	if (map)
		free(map);
	return (1);
}

int		get_size(char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\n')
	{
		i++;
	}
	return (i);
}

int		placing_figure_help(char *map, int zero, char a)
{
	if ((zero < get_size(map) * (get_size(map) + 1)) && map[zero] == '.')
	{
		map[zero] = a;
		return (1);
	}
	else
		return (0);
}
