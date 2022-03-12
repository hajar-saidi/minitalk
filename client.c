/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:59:23 by hsaidi            #+#    #+#             */
/*   Updated: 2022/03/12 22:05:02 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_mesage(pid_t pid, char c)
{
	int	shift;

	shift = 7;
	while (shift >= 0)
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
		shift--;
		printf("%d\n",SIGUSR1);
		printf("%d\n",SIGUSR2);
		usleep(200);
	}
}

void	send(char *input, pid_t pid)
{
	int	i;

	i = 0;
	while (input[i])
	{
		send_mesage(pid, input[i]);
		i++;
	}
	send_mesage(pid, '\0');
}

int pid_check(char *id)
{
	pid_t pid;
	pid = ft_atoi(id);
	if (id == NULL || id == 0)
	{
		ft_putstr("u need pid\n");
		exit (1);
	}
	while(*id)
	{
		if(*id < '0' || *id > '9')
		{
			ft_putstr("check ur pid\n");
			exit(1);
		}
		id++;	
	}
	return(pid);
}

int	main(int argc, char **argv)
{
   int	pid;

   if (argc != 3)
   {
   	printf("client: invalid arguments\n");
   	exit(EXIT_FAILURE);
   }
   else
   {
		pid =pid_check(argv[1]);
		send(argv[2],pid);
		printf("done\n");
   }
   exit(0);
}
