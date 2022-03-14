/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:59:23 by hsaidi            #+#    #+#             */
/*   Updated: 2022/03/14 22:42:06 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_mesage(pid_t pid, char c)
{
	int	shift;

	shift = 0;
	while (shift < 8)
	{
		if (c & (1 << shift))
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		shift++;
		usleep(400);
	}
}

void	send(char *str, pid_t pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_mesage(pid, str[i]);
		i++;
	}
	send_mesage(pid, '\0');
}

int	pid_check(char *id)
{
	pid_t	pid;

	pid = ft_atoi(id);
	if (id == NULL || id == 0)
	{
		ft_putstr("Check pid\n");
		exit (1);
	}
	while (*id)
	{
		if (*id < '0' || *id > '9')
		{
			ft_putstr("WAIT check your pid!\n");
			exit(1);
		}
		id++;
	}
	return (pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("You need pid and msg...\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		pid = pid_check(argv[1]);
		send(argv[2], pid);
		ft_putstr("DONE.\n");
	}
	exit(0);
}
