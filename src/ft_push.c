/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:03:51 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/10 15:15:07 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_sign(t_mods *mods, char **mas, int i, char *str)
{
	if (str[0] == '-')
		(*mas)[i++] = '-';
	else if ((mods->flags.hash == o && str[0] != '0')
			|| mods->flags.hash == x || mods->flags.hash == X)
	{
		(*mas)[i++] = '0';
		if (mods->flags.hash == x)
			(*mas)[i++] = 'x';
		if (mods->flags.hash == X)
			(*mas)[i++] = 'X';
	}
	else if (mods->flags.plus)
		(*mas)[i++] = '+';
	else if (mods->flags.space)
		(*mas)[i++] = ' ';
	return (i);
}

static int	ft_put_content(t_mods *mods, char **mas, int i, char *str)
{
	int		j;
	int		len;
	int		precision;

	len = ft_strlen(str);
	precision = mods->precision - len;
	j = 0;
	if (str[0] == '-')
	{
		j++;
		precision++;
	}
	while (precision-- > 0)
		(*mas)[i++] = '0';
	while (str[j])
		(*mas)[i++] = str[j++];
	return (i);
}

static int	ft_reg_i(t_mods *mods, int i, char *str, int len)
{
	if (((mods->flags.plus || mods->flags.space) && str[0] != '-')
			|| mods->flags.hash == o)
		i--;
	if (mods->precision >= len && str[0] == '-')
		i--;
	if (mods->flags.hash == x || mods->flags.hash == X)
		i -= 2;
	return (i);
}

void		ft_push_right(t_mods *mods, char **mas, int size, char *str)
{
	int		i;
	int		val;
	int		len;

	if (mods->precision < 0 && mods->flags.zero)
	{
		i = ft_put_sign(mods, mas, i, str);
		if (str[0] == '-')
			str++;
		len = ft_strlen(str);
		while (i < size - len)
			(*mas)[i++] = '0';
	}
	else
	{
		i = 0;
		len = ft_strlen(str);
		val = (len > mods->precision) ? size - len : size - mods->precision;
		while (i < val)
			(*mas)[i++] = ' ';
		i = ft_reg_i(mods, i, str, len);
		i = ft_put_sign(mods, mas, i, str);
	}
	i = ft_put_content(mods, mas, i, str);
	(*mas)[i] = '\0';
}

void		ft_push_left(t_mods *mods, char **mas, int size, char *str)
{
	int		i;

	i = ft_put_sign(mods, mas, 0, str);
	i = ft_put_content(mods, mas, i, str);
	while (i < size)
		(*mas)[i++] = ' ';
	(*mas)[i] = '\0';
}
