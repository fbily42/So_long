/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:19:53 by fbily             #+#    #+#             */
/*   Updated: 2022/05/20 18:49:41 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	size_t			size;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	size = ft_strlen(s);
	while (i < size)
	{
		f(i, &s[i]);
		i++;
	}
}
