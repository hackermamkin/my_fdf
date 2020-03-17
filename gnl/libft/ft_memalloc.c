/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:24:34 by gfreddie          #+#    #+#             */
/*   Updated: 2019/09/15 16:38:14 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char		*mem;

	mem = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
