/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:58:51 by hsaidi            #+#    #+#             */
/*   Updated: 2022/03/14 22:37:05 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *k)
{
	if (!k)
		return ;
	while (*k)
	{
		ft_putchar(*k);
		k++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	x;
	unsigned int	t;

	t = n;
	if (n < 0)
	{
		ft_putchar('-');
		t = -n;
	}
	if (t >= 10)
	{
		x = t % 10;
		ft_putnbr(t / 10);
		ft_putchar(x + 48);
	}
	else
		ft_putchar(t + 48);
}
