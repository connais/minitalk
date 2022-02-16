/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:38:20 by avaures           #+#    #+#             */
/*   Updated: 2022/02/16 17:27:36 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c, int i)
{
	if (c >> i & 1)
	{
		if (kill(pid, SIGUSR1) < 0)
			exit(EXIT_FAILURE);
	}
	else
	{
		if (kill(pid, SIGUSR2) < 0)
			exit(EXIT_FAILURE);
	}
}

static void mt_kill(int pid, char *str)
{
	static int	i = 8;
	static char	c;
	static char	*s2;

	if (!s2)
	{
		s2 = str;
		c = *s2;
	}
	if (c)
	{
		if (i--)
			send_char(pid, c, i);
		else
		{
			i = 8;
			c = *++s2;
			if (c)
				mt_kill(pid, str);
			else
				kill(pid, SIGUSR2);
		}
	}
	else
		kill(pid, SIGUSR2);
}

static void action(int sig, siginfo_t *info, void *context)
{
	(void) context;
	if (sig == SIGUSR2)
		mt_kill(info->si_pid, "");
	else if (sig == SIGUSR1)
	{
		ft_printf("biit recu !!\n");
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char **argv)
{
	struct sigaction	s_sigaction;
	
	mt_kill(ft_atoi(argv[1]), argv[2]);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
