/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:56:33 by fio               #+#    #+#             */
/*   Updated: 2025/03/26 20:06:18 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void convertor(va_list args, const char format)
{
	if (format == 'd' || format == 'i')
		conv2int(va_arg(args, int));
	if (format == 's')
		conv2str(va_arg(args, char *));
	if (format == 'c')
		ft_putchar(va_arg(args, char));
}

void ft_printf(const char *format, ...)
{
	va_list args;
	int i;

	va_start (args, format);
	i = 0;

	while (format[i])
	{
		if (format[i] == '%' && (*(format + 1) != '%'))
		{
			convertor(args, format[i + 1]);
			i = i + 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
    	}
	}
}
