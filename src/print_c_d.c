/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: problem <problem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:05:20 by problem           #+#    #+#             */
/*   Updated: 2023/01/10 15:05:21 by problem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	lenght_num(long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr(long n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	print_c(n % 10 + '0');
}

int	print_d(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		print_c('-');
		len = 1;
	}
	ft_putnbr(nb);
	len += lenght_num(nb);
	return (len);
}