/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <gfreddie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:14:54 by gfreddie          #+#    #+#             */
/*   Updated: 2019/09/15 16:38:56 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (void *)s1;
	str2 = (void *)s2;
	while (n && *str1 == *str2)
	{
		n--;
		str1++;
		str2++;
	}
	if (!n)
		return (0);
	return (*str1 - *str2);
}
