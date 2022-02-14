/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:59:28 by avaures           #+#    #+#             */
/*   Updated: 2022/02/11 12:51:00 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	is_null(char *test);
int	ft_putnbr_base(int nb);
int	lennbr_dec(signed int nb);
int	ft_putnbr_dec(signed int nb);
int	lennbrhexa(signed int nb);
int	ft_putnbrhexa(signed int nb, char c);
int	ft_putnbrptr(unsigned long long nb, char *base);
int	lennbrptr(signed long long nb);
int	lennbr(int nb);
int	found(char c, va_list aq);
int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr_base(int nb);
#endif
