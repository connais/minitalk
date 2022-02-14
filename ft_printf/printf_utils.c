/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:00:16 by avaures           #+#    #+#             */
/*   Updated: 2022/02/11 11:24:19 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_base(int nb)
{
	int	res;

	res = lennbr(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_base(nb / 10);
		ft_putnbr_base(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (res);
}

int	ft_putnbrhexa(signed int nb, char c)
{
	char			*base;
	int				res;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	res = lennbrhexa(nb);
	if (nb < 0)
		nb *= -1;
	if (nb > 15)
	{
		ft_putnbrhexa(nb / 16, c);
		ft_putnbrhexa(nb % 16, c);
	}
	else
		ft_putchar(base[nb]);
	return (res);
}

int	ft_putnbr_dec(signed int nb)
{
	int	res;

	res = lennbr_dec(nb);
	if (nb < 0)
		nb = 4294967295 - (nb - 1);
	if (nb > 9)
	{
		ft_putnbr_base(nb / 10);
		ft_putnbr_base(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (res);
}

int	ft_putnbrptr(unsigned long long nb, char *base)
{
	int	res;

	res = lennbrptr(nb);
	if (nb > 15)
	{
		ft_putnbrptr(nb / 16, base);
		ft_putnbrptr(nb % 16, base);
	}
	else
		ft_putchar(base[nb]);
	return (res);
}
