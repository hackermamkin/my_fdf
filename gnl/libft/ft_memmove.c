/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <gfreddie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 19:18:11 by gfreddie          #+#    #+#             */
/*   Updated: 2019/09/15 16:39:43 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dup_src;
	unsigned char	*dup_dst;

	dup_src = (unsigned char *)src;
	dup_dst = (unsigned char *)dst;
	if ((dst == NULL && src == NULL) || dst == src)
		return (NULL);
	if (dst > src)
		while (len--)
			dup_dst[len] = dup_src[len];
	else if (src > dst)
		while (len--)
			*dup_dst++ = *dup_src++;
	return (dst);
}
