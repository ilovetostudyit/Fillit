/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 03:57:57 by ehaggon           #+#    #+#             */
/*   Updated: 2019/01/16 15:05:28 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *temp;

	temp = (unsigned char*)b;
	while (len > 0)
	{
		*temp = (unsigned char)c;
		temp++;
		len--;
	}
	return (b);
}
