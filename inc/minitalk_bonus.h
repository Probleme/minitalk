/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: problem <problem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:05:46 by problem           #+#    #+#             */
/*   Updated: 2023/01/10 15:05:47 by problem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
// #include <sys/siginfo.h>

int	ft_atoi(const char *str);
int	ft_printf(const char *str, ...);
int	print_c(int c);
int	print_d(int n);

#endif