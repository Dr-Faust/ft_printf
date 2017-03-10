/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:36:59 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/10 11:38:26 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_end_zeroes(char *str, char c, char r)
{
	char	*s;
	char	a;

	s = str;
	if (str && *str)
	{
		a = *str;
		*str = 0;
		str++;
		while (*str)
			str++;
		if (s - str)
			while (*(--str) == c)
				*str = r;
		*s = a;
	}
	return (s);
}
