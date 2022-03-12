/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:58:51 by hsaidi            #+#    #+#             */
/*   Updated: 2022/03/12 15:20:03 by hsaidi           ###   ########.fr       */
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
static int	ft_checklong(int res, int count, int is_neg)
{
	if (count > 19)
	{
		if (is_neg == -1)
			return (0);
		else if (is_neg == 1)
			return (-1);
	}
	return (res * is_neg);
}
//19 is the lent of long long

static int	ft_loop(const char *str, int i, int count, int is_neg)
{
	int	p;
	int	res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
		count++;
	}
	p = ft_checklong(res, count, is_neg);
	return (p);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	is_neg;
	int	count;
	int	p;

	is_neg = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	count = 0;
	p = ft_loop(str, i, count, is_neg);
	return (p);
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
