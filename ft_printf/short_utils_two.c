/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:44:37 by avaures           #+#    #+#             */
/*   Updated: 2022/02/11 11:29:02 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

int	lennbr_dec(signed int nb)
{
	int	res;

	res = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = 4294967295 - (nb - 1);
	while (nb > 0)
	{
		nb /= 10;
		res++;
	}
	return (res);
}

int	lennbrptr(signed long long nb)
{
	signed long long	nbr;
	int					res;

	res = 0;
	nbr = nb;
	if (nb >= 0 && 15 >= nb)
		return (3);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		res++;
	}
	res += 2;
	return (res);
}
