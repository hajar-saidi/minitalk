/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:13:56 by hsaidi            #+#    #+#             */
/*   Updated: 2022/03/03 14:17:07 by hsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
// int	main (void)
// {
// 	printf("%d\n",atoi("2147483649"));
// 	printf("%d",ft_atoi("2147483649"));
// }
