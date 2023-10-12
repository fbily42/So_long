/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:41:47 by fbily             #+#    #+#             */
/*   Updated: 2022/06/02 15:29:57 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		which_print(char c, va_list args);
int		print_char(unsigned char c);
int		print_str(const char *str);
int		print_int(va_list args);
int		int_size(long nb);
int		hexa_size(unsigned int nbr);
int		print_unsigned_int(va_list args);
int		print_ptr(va_list args);
int		ptr_size(unsigned long long ptr);
int		print_hexa(va_list args, char c);
void	ft_putnbr_int(int nb);
void	ft_putnbr_unsigned_int(unsigned int nb);
void	putnbr_hexa(unsigned int nbr);
void	putptr_hexa(unsigned long long nbr);
void	putnbr_maj_hexa(unsigned int nbr);

#endif