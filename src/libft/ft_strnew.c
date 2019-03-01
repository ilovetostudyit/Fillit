/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:29:15 by ehaggon           #+#    #+#             */
/*   Updated: 2019/01/16 15:02:15 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;

	if (size == (size_t)-1)
		return (NULL);
	str = ft_memalloc(size + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}
