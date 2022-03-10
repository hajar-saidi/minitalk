/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:01:45 by hsaidi            #+#    #+#             */
/*   Updated: 2022/03/10 17:53:02 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum)
{
	static char	c;
	static int	bits = 7;

	if (signum == SIGUSR1)
		c |= (1 << bits);
	else if (signum == SIGUSR2)
		c &= ~(1 << bits);
	bits--;
	if (bits == -1)
	{
		write(1, &c, 1);
		bits = 7;
		if (c == '\0')
		{
			write(1, "\n", 1);
			c = 0;
		}
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID : %d\n", pid);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
}

