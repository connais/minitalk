/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:39:18 by avaures           #+#    #+#             */
/*   Updated: 2022/02/16 15:02:03 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	treat_bit(int *pid, char c, char **s2, char *s)
{
	char *temp;

	if (!c || s[4094])
	{
		temp = *s2;
		*s2 = ft_strjoin(*s2, s);
		if (!(*s2))
			exit(EXIT_FAILURE);
		free(temp);
		add_char(s, '\0', 1);
	}
	if (!c)
	{
		ft_printf("%s\n", *s2);
		ft_bzero(*s2, ft_strlen(*s2));
		free(*s2);
		*s2 = NULL;
		kill(*pid, SIGUSR1);
		add_char(s, '\0', 1);
		*pid = -1;
		return (8);
	}
	add_char(s, c, 0);
	return (8);

}
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

static void actserv(int sig, siginfo_t *info, void *context)
{
	static int		pid = 0;
	static int		i = 8;
	static char		s[4096];
	static char		*s2;
	static unsigned	char	c = 0;
	(void) context;

	if (pid != info->si_pid)
		pid = reset_info2(s, reset_info(&i, &c, info->si_pid, &s2));
	if (!s2)
	{
		s2 = malloc(sizeof(unsigned char) * i);
		if (!s2)
			exit(EXIT_FAILURE);
		s2[0] = '\0';
	}
	if (sig == SIGUSR1)
		c = c + ft_power(2, i - 1);
	if ((--i) == 0)
	{
		i = treat_bit(&pid, c, &s2, s);
		c = 0;
	}
	if (pid && pid != -1)
		kill(info->si_pid, SIGUSR2);
	return ;
}

int	main()
{
	struct sigaction	s_sigaction;
	
	s_sigaction.sa_sigaction = actserv;
	s_sigaction.sa_flags = SA_SIGINFO;
	ft_printf("PID : %d\n", getpid());
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();

	return (0);
}
