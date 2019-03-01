/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:31:30 by ehaggon           #+#    #+#             */
/*   Updated: 2019/01/16 14:52:51 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	size_t	len1;
	size_t	len2;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = NULL;
	res = ft_strnew(len1 + len2);
	if (res == NULL)
		return (NULL);
	ft_strcat(res, s1);
	ft_strcat(res, s2);
	return (res);
}
