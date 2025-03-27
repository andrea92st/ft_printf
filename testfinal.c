/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfinal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:47:21 by fio               #+#    #+#             */
/*   Updated: 2025/03/27 02:52:58 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	conv2str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	conv2hexp(unsigned long n, char *base)
{
	if (n >= 16)
		conv2hexp(n / 16, base);
	ft_putchar(base[n % 16]);
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

static void	ft_u2char(unsigned int i)
{
	char	c;

	c = (i + 48);
	write (1, &c, 1);
}

void	conv2u(unsigned int n)
{
	if (n > 9)
	{
		conv2u(n / 10);
		ft_u2char(n % 10);
	}
	else
		ft_u2char(n);
}

static void	convertor(va_list args, const char format)
{
	void	*ptr;

	if (format == 'd' || format == 'i')
		conv2int(va_arg(args, int));
	if (format == 's')
		conv2str(va_arg(args, char *));
	if (format == 'c')
		ft_putchar(va_arg(args, int));
	if (format == '%')
		ft_putchar('%');
	if (format == 'p')
	{
		ptr = va_arg(args, void *);
		write(1, "0x", 2);
		conv2hexp((unsigned long)ptr, "0123456789abcdef");
	}
	if (format == 'u')
		conv2u(va_arg(args, int));
}

static void	convertor2(va_list args, const char format)
{
	unsigned int	n;

	if (format == 'x')
	{
		n = va_arg(args, unsigned int);
		conv2hexp(n, "0123456789abcdef");
	}
	if (format == 'X')
	{
		n = va_arg(args, unsigned int);
		conv2hexp(n, "0123456789ABCDEF");
	}
}

void	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start (args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'x' || format[i + 1] == 'X')
				convertor2(args, format[i + 1]);
			else
				convertor(args, format[i + 1]);
			i = i + 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
}

int main ()
{
	int numero = 54;
	int ad = 92;
	char *str = "weweweww";
	int *ptr = &ad;
	char c ='k';
	int x = 45;
	unsigned int u = 564564;

	ft_printf("int = %i\nstr = %s\nptr = %p\nchar = %c \n100 = %% \n", ad, str, ptr, c);
	printf("int = %i\nstr = %s\nptr = %p\nchar = %c \n100 = %% \n", ad, str, ptr, c);
	ft_printf("\n\n");
	ft_printf("x = %x, X = %X u = %u\n",x ,x ,u);
	printf("x = %x, X = %X u = %u",x ,x, u);
	return (0);
}
