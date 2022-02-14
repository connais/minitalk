/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:11:10 by avaures           #+#    #+#             */
/*   Updated: 2021/12/21 17:16:40 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *c, ...)
{
	int			len;
	int			sheesh;
	int			i;
	va_list		aq;	

	sheesh = 0;
	len = 0;
	if (!c)
		return (len);
	va_start(aq, c);
	i = 0;
	while (c[i])
	{
		if (c[i] != '%')
			ft_putchar(c[i]);
		else
		{
			len += found(c[i++ + 1], aq);
			sheesh++;
		}
		i++;
		len++;
	}
	va_end(aq);
	return (len - sheesh);
}

int	is_null(char *test)
{
	int	len;

	len = 0;
	if (test == NULL)
		len = ft_putstr("(null)");
	else
		len = ft_putstr(test);
	return (len);
}

int	found(char c, va_list aq)
{
	int		len;
	char	*test;

	len = 0;
	if (c == 'i' || c == 'd')
		len = ft_putnbr_base(va_arg(aq, int));
	else if (c == 'u')
		len = ft_putnbr_dec(va_arg(aq, int));
	else if (c == 'c')
		len = ft_putchar(va_arg(aq, int));
	else if (c == 's')
	{
		test = va_arg(aq, char *);
		len = is_null(test);
	}
	else if (c == 'p')
	{
		write(1, "0x", 2);
		len = ft_putnbrptr(va_arg(aq, unsigned long long), "0123456789abcdef");
	}
	else if (c == 'x' || c == 'X')
		len = ft_putnbrhexa(va_arg(aq, unsigned int), c);
	else if (c == '%')
		len = ft_putchar(c);
	return (len);
}
