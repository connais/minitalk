/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:44:52 by avaures           #+#    #+#             */
/*   Updated: 2022/02/16 14:58:21 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "LIBFT/libft.h"
#include "ft_printf/ft_printf.h"


int		treat_bit(int *pid, char c, char **s2, char *s);
int		ft_power(int number, int power);
int		reset_info(int *i, unsigned char *c, int newPid, char **s2);
int		reset_info2(char *s, int newPid);
void		add_char(char *s, char c, int reset);
void		send_char(int pid, char c, int i);
void		client(int identify, char *str);
static void	mt_kill(int pid, char *str);
static void	action(int sig, siginfo_t *info, void *context);
static void	actserv(int sig, siginfo_t *info, void *context);

#endif
