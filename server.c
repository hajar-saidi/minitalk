/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:01:45 by hsaidi            #+#    #+#             */
/*   Updated: 2022/03/13 22:39:29 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_asci(int sig)
{
	static char c;
	static int i;
	
	//printf("im here\n");
	//printf("sig=%d\n",sig);
	if (sig == SIGUSR1)
	{
		//printf("i =%d\n",i);
		c +=(1 << i);
	}
	i++;
	if(i == 8)
	{
		write(1,&c,1);
		if(c == '\0')
			write(1,"\n",1);
		i = 0;
		c = 0;
	}
	 
}
int main(int ac,char **av)
{
	pid_t pid;
	pid = getpid();
	write(1,"PID:",5);
	ft_putnbr(pid);
	write(1,"\n",1);
	signal(SIGUSR1,send_asci);
	signal(SIGUSR2,send_asci);
	while(1)
		pause();
}
