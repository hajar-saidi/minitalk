/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:59:23 by hsaidi            #+#    #+#             */
/*   Updated: 2022/03/09 20:39:46 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void convert(pid_t pid,char c)
{
	int nb;
	
	nb = 7;
	while(nb >= 0)
	{
		if()
	}
	
} 

static void	send_char(pid_t pid, char c)
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
		usleep(300);
	}
}

int take_the_str(char *str,pid_t pid)
{
	int i;
	while (str[i])
	{
		
	}
	
}

int	main(int argc, char **argv)
{
   int	pid;

   if (argc != 3)
   {
   	printf("client: invalid arguments\n");
   	exit(EXIT_FAILURE);
   }
   pid = atoi(argv[1]);
   kill(pid, SIGUSR1);
   return (0);
}

