/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:21:09 by avaures           #+#    #+#             */
/*   Updated: 2022/02/14 16:13:07 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "LIBFT/libft.h"
#include "ft_printf/ft_printf.h"

int which_send(char c)
{
	if (c == '0')
		return (0);
	else
		return (1);
}
char *change_base(int alpha)
{
	int	i;
	int	j;
	char	*str_number;
	str_number = malloc(sizeof(char) * 9);
	if (!str_number)
		return (NULL);
	i = 8;
	j = 0;
	ft_printf("I : %d\n", i);
	while (i--)
	{
		ft_printf("I : %d\n", i);
		ft_printf("str_number[%d]\n", j);
		str_number[j++] = (alpha >> i & 1) + 48;
		ft_printf("str_number[%d]", j);
	}
	str_number[j] = '\0';
	return (str_number);
}
void client(int identify, char *str)
{
	int	i;
	int	j;
	char	*send;
	
	i = 0;
	j = 0;
	while(str[i])
	{
		send = change_base(str[i]);
		if (!send)
		{
			free(send);
			send = NULL;
		}
		while (send[j])
		{
			if (send[j] == '0')
				kill(identify, SIGUSR1);
			else 
				kill(identify, SIGUSR2);
			usleep(200);
			j++;
		}
		free(send);
		i++;
		j = 0;
	}
	return ;
}

int main(int argc, char **argv)
{
	client(ft_atoi(argv[1]), argv[2]);
	return (0);

}
