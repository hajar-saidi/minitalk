/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:59:23 by hsaidi            #+#    #+#             */
/*   Updated: 2022/03/10 22:26:18 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	send_mesage(int pid, char *str)
{
	int	result;
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			result = str[i] >> j & 1;
			if (result == 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			j++;
		}
		i++;
	}
}
void	signal(int piid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(piid, SIGUSR2);
		usleep(100);
		i++;
	}
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
		pid_check(argv[1]);
		send_mesage(pid, argv[2]);
	  	signal(pid);
   } 
   exit(0);
}
