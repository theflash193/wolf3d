/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:51:49 by grass-kw          #+#    #+#             */
/*   Updated: 2014/04/27 17:51:56 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*tmp_dest;
	unsigned char		*tmp_src;
	unsigned char		*tmp;
	unsigned int		i;

	tmp_dest = (unsigned char *)s1;
	tmp_src = (unsigned char *)s2;
	tmp = malloc(sizeof(*s2) * (n));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		tmp[i] = tmp_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		tmp_dest[i] = tmp[i];
		i++;
	}
	return (s1);
}
