/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: problem <problem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:05:24 by problem           #+#    #+#             */
/*   Updated: 2023/01/10 15:05:26 by problem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	ft_callspecifier(char c, va_list args)
{

	if (c == '%')
		return (print_c('%'));
	else if (c == 'c')
		return (print_c(va_arg(args, int)));
	else if (c == 'd')
		return (print_d(va_arg(args, int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	if (!str)
		return (0);
	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str)
				break ;
			len += ft_callspecifier(str[i], args);
		}
		else
			len += print_c(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}