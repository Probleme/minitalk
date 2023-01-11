/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: problem <problem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:04:55 by problem           #+#    #+#             */
/*   Updated: 2023/01/10 15:04:56 by problem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int	ft_atoi(const char *str);
int	ft_printf(const char *str, ...);
int	print_c(int c);
int	print_d(int n);

#endif