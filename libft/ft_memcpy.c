/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:52:42 by grass-kw          #+#    #+#             */
/*   Updated: 2014/04/27 17:52:45 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	int			i;
	char		*tmp;
	const char	*ptr;

	tmp = s1;
	ptr = s2;
	i = 0;
	while (n > 0)
	{
		tmp[i] = ptr[i];
		i++;
		n--;
	}
	return (s1);
}
