/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:06:43 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/06 19:53:22 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long long	ft_cast_ll(long double value, int base)
{
	long long	val;
	int			neg;
	long double	n;

	neg = 1;
	if (value < 0)
	{
		value = -value;
		neg = -1;
	}
	printf("value = %lld\n", (long long)value);
	n = value - (long long)value;
	printf("n = %Lf\n", n);
	while (n < 1)
	{
		value *= 10;
		n = value - (long long)value;
		printf("n = %Lf\n", n);
		val = value;
	}
	printf("val = %d\n", (int)val);
	return (val * neg);
}

static int			ft_size(long double val, int base)
{
	int		size;

	size = 1;
	if (val < 0 && base == 10)
		size++;
	val = (val < 0) ? -val : val;
	while (val >= base)
	{
		val /= base;
		size++;
	}
	return (size);
}

char				*ft_fitoa_base(long double value, int base)
{
	char		*str;
	char		*bs;
	int			size;
	long long	val;

	bs = "0123456789ABCDEF";
	val = ft_cast_ll(value, base);
	printf("val = %d\n", (int)val);
	size = ft_size(value, base);
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	val = (val < 0) ? -val : val;
	if (val == 0)
		str[0] = '0';
	while (val > 0)
	{
		str[--size] = bs[val % base];
		val /= base;
	}
	str[0] = (str[0]) ? str[0] : '-';
	return (str);
}

int			main(void)
{
	double	a;

	a = 712.017;
	printf("%s\n", ft_fitoa_base(a,  10));
	return (0);
}
