/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:09:39 by fio               #+#    #+#             */
/*   Updated: 2025/03/26 18:26:27 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void conv2str(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

static void	ft_int2char(int i)
{
	char	c;

	c = (i + 48);
	write (1, &c, 1);
}

void	conv2int(int n)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
        conv2int(n / 10);
		ft_int2char(n % 10);
	}
	else
		ft_int2char(n);
}

void convertor(va_list args, const char format)
{
	if (format == 'd')
		conv2int(va_arg(args, int));
	if (format == 's')
		conv2str(va_arg(args, char *));
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

int main ()
{
	int numero = 54;
	int ad = 92;
	char *str = "weweweww";
	ft_printf("bonjourt jai %d ans %s et chui du %d zarma", numero, str, ad);
	return (0);
}