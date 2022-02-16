/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:58:03 by avaures           #+#    #+#             */
/*   Updated: 2022/02/16 14:42:54 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	lennbr(int nb)
{
	int	nbr;
	int	res;

	res = 0;
	nbr = nb;
	if (nb == 0)
		return (1);
	if (nbr <= 0)
	{
		nbr *= -1;
		res++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		res++;
	}
	return (res);
}

int	lennbrhexa(signed int nb)
{
	signed int	nbr;
	int				res;

	res = 0;
	nbr = nb;
	if (nb >= 0 && 15 >= nb)
		return (1);
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		res++;
	}
	return (res);
}
/*
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
