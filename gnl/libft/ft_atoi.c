/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:37:22 by gfreddie          #+#    #+#             */
/*   Updated: 2019/09/13 16:47:01 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str1)
{
	long long int	index;
	long long int	s;
	long long int	t;

	s = 0;
	t = 1;
	index = 0;
	while ((str1[index] >= 9 && str1[index] <= 13) || str1[index] == 32)
		index++;
	if (str1[index] == 43)
		index++;
	else if (str1[index] == '-')
	{
		index++;
		t = -1;
	}
	while (str1[index] != '\0')
	{
		if (str1[index] < 48 || str1[index] > 57)
			return (s * t);
		s = s * 10;
		s = s + (str1[index++] - 48);
	}
	return (s * t);
}
