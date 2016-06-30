/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:52:51 by grass-kw          #+#    #+#             */
/*   Updated: 2014/03/23 18:53:17 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_pow(int n, int pow)
{
	long	i;
	long	total;

	i = 0;
	total = 1;
	while (i < pow)
	{
		total = total * n;
		i++;
	}
	return (total);
}

char		*ft_itoa(int m)
{
	int		len;
	int		i;
	int		neg;
	char	*str;
	long	n;

	n = m;
	len = 1;
	i = 0;
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	while (ft_pow(10, len) <= n)
		len++;
	str = (char *)ft_strnew(len + 1);
	if (neg)
		str[i++] = '-';
	while (len > 0)
	{
		str[i] = (n / ft_pow(10, len - 1)) % 10 + '0';
		i++;
		len--;
	}
	return (str);
}
