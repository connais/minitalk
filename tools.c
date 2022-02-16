/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:18:04 by avaures           #+#    #+#             */
/*   Updated: 2022/02/16 17:35:55 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	add_char(char *s, char c, int reset)
{
	static int	j = 0;
	
	if (reset)
	{
		j = 0;
		ft_bzero(s, 4096);
		s[0] = '\0';
	}
	else
		s[j++] = c;
}

int	reset_info(int *i, unsigned char *c, int newPid, char **s2)
{
	*i = 8;
	*c = 0;
	if (*s2 && *s2[0])
	{
		ft_bzero(*s2, ft_strlen(*s2));
		free(s2);
		*s2 = NULL;
	}
	return (newPid);
}

int	reset_info2(char *s, int newPid)
{
	add_char(s, '\0', 1);
	return (newPid);
}
