/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 02:08:08 by ataouaf           #+#    #+#             */
/*   Updated: 2023/01/17 02:08:09 by ataouaf          ###   ########.fr       */
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