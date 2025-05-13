/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:56:33 by fio               #+#    #+#             */
/*   Updated: 2025/05/14 00:07:49 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convertor3(va_list args)
{
	void			*ptr;
	int				len;

	len = 0;
	ptr = va_arg (args, void *);
	if (ptr == NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len = len + 2;
	len += conv2hexp((size_t)ptr, "0123456789abcdef");
	return (len);
}

static int	convertor2(va_list args, const char format)
{
	unsigned int	n;
	int				len;

	len = 0;
	if (format == 'p')
		len += convertor3(args);
	else if (format == 'x')
	{
		n = va_arg(args, unsigned int);
		len += conv2hexp((unsigned long)n, "0123456789abcdef");
	}
	else if (format == 'X')
	{
		n = va_arg(args, unsigned int);
		len += conv2hexp((unsigned long)n, "0123456789ABCDEF");
	}
	return (len);
}

static int	convertor(va_list args, const char format)
{
	int		len;

	len = 0;
	if (format == 'd' || format == 'i')
		len += conv2int(va_arg(args, int));
	else if (format == 's')
		len += conv2str(va_arg(args, char *));
	else if (format == 'c')
	{
		ft_putchar(va_arg(args, int));
		len++;
	}
	else if (format == '%')
	{
		ft_putchar('%');
		len++;
	}
	else if (format == 'u')
		len += conv2u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X' || format == 'p')
		len += convertor2(args, format);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start (args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += convertor(args, format[i + 1]);
			i = i + 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}
