/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 22:17:47 by flamby            #+#    #+#             */
/*   Updated: 2022/06/02 15:29:55 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_char(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(const char *str)
{
	int			i;

	i = 0;
	if (str == NULL)
	{
		i = print_str("(null)");
		return (i);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}
