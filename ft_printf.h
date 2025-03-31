/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:54:28 by fio               #+#    #+#             */
/*   Updated: 2025/03/31 12:02:26 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		conv2hexp(unsigned long n, char *base);
int		conv2str(char *str);
int		conv2int(int n);
int		conv2u(unsigned int n);

#endif
