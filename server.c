/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:01:45 by hsaidi            #+#    #+#             */
/*   Updated: 2022/03/12 22:04:53 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_asci(int sig)
{
	static char c;
	static int i;
	
	if (sig == SIGUSR2)
		c +=(1 << i);
	// printf("%d\n",SIGUSR1);
	// printf("%d\n",SIGUSR2);
	// else if (sig = SIGUSR2)
	// 	c += (0 << i);
		i++;
	if(c == 8)
	{
		write(1,&c,1);
		if(c == '\0')
			write(1,"\n",1);
	}
	i = 0;
	c = 0; 
}
int main(int ac,char **av)
{
	pid_t pid;
	pid = getpid();
	write(1,"PID:",5);
	ft_putnbr(pid);
	signal(SIGUSR1,send_asci);
	signal(SIGUSR2,send_asci);
	while(1)
		pause();
}
