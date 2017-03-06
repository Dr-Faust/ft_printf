/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:26:56 by opodolia          #+#    #+#             */
/*   Updated: 2016/12/04 20:45:33 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *dest;

	dest = dst;
	while (len > 0 && *src)
	{
		*dest++ = *src++;
		len--;
	}
	while (len--)
		*dest++ = 0;
	return (dst);
}
