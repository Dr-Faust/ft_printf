/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:03:51 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/10 19:56:15 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*ft_cut_zeroes(char **str)
{
	int		i;
	char	*s;
	char	*tmp;

	i = 0;
	tmp = *str;
	while (tmp[i] != '.')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	s = ft_strncpy(s, tmp, i);
	return (s);
}
static void ft_main_part(t_mods *mods, char **mas, int size, char *str)
{
	int		i;
	int		val;
	int		len;
	int		j_len;

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
void		ft_push_right(t_mods *mods, char **mas, int size, char *str)
{
	int		size_1;
	int		len;

	ft_main_part(mods, mas, size, str);
	if (mods->flags.hash == no && mods->f_l_a_g &&
			(mods->qualifier == 'g' || mods->qualifier == 'G'))
		*mas = (ft_cut_zeroes(mas));
	if (mods->flags.hash == no && (mods->qualifier == 'g'
				|| mods->qualifier == 'G'))
	{
		size_1 = ft_strlen(*mas);
		while ((*mas)[--size_1] == '0')
			(*mas)[size_1] = 0;
	}
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
