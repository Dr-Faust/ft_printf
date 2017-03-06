/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:10:28 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/06 19:53:37 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_float(va_list ap, t_mods *mods)
{
	int		size;
	int		ret;
	char	c;
	char	*str;
	char	*mas;

	c = mods->qualifier;
	if (c == 'f' || c == 'e' || c == 'g' || c == 'a')
		str = ft_convert_len(ap, mods, len);
	size = ft_size(str, mods);
	mas = (char *)malloc(sizeof(char) * (size + 1));
	mods->flags.left ? ft_push_left(mods, &mas, size, str) :
		ft_push_right(mods, &mas, size, str);
	ft_putstr(mas);
	free(str);
	free(mas);
	return (ret);
}
