/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:12:31 by ehaggon           #+#    #+#             */
/*   Updated: 2019/01/16 15:07:41 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *var;

	var = (unsigned char*)malloc(size);
	if (var == NULL)
		return (NULL);
	ft_bzero(var, size);
	return (var);
}
