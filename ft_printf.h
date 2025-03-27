/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:54:28 by fio               #+#    #+#             */
/*   Updated: 2025/03/27 02:55:58 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_printf(const char *format);
void	conv2hexp(unsigned long n);
void	conv2str(char *str);
void	conv2int(int n);
void	ft_putchar(char c);
void	conv2u(unsigned int n);

#endif
