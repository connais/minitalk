/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:39:49 by avaures           #+#    #+#             */
/*   Updated: 2022/02/14 15:36:35 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "LIBFT/libft.h"
#include "ft_printf/ft_printf.h"

int	ft_power(int number, int power)
{
	int res;

	res = number;
	if (power <= 0)
		return(1);
	else if (power == 1)
		return (number);
	while (power > 1)
	{
		res *= number; 
		power--;
	}
	return (res);
}
void	bonjour(int sig)
{
	static int	c = 0;
	static int	i = 8;
	
	if (sig == SIGUSR2)
		c = c + ft_power(2, i - 1);
	if (--i == 0)
	{
		write(1, &c, 1);
		c = 0;
		i = 8;
	}
	return;
}
int main(void)
{
	int	i;
	char	str[8];
	ft_printf("PID : %d\n", getpid());
	signal(SIGUSR1, bonjour);
	signal(SIGUSR2, bonjour);
	while (1)
		pause();
	return (0);
}
