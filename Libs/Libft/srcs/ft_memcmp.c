/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:04:20 by fbily             #+#    #+#             */
/*   Updated: 2022/05/20 19:01:17 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cp_s1;
	unsigned char	*cp_s2;
	size_t			i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	cp_s1 = (unsigned char *)s1;
	cp_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (cp_s1[i] == cp_s2[i])
			i++;
		else
			return (cp_s1[i] - cp_s2[i]);
	}
	return (cp_s1[i - 1] - cp_s2[i - 1]);
}
