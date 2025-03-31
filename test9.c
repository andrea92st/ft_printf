

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>


void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	conv2hexp(unsigned long n, char *base)
{
	int len;

	len = 0;
	if (n >= 16)
		len +=conv2hexp(n / 16, base);
	ft_putchar(base[n % 16]);
	len++;
	return (len); 
}

static void	ft_int2char(int i)
{
	char	c;

	c = (i + 48);
	write (1, &c, 1);
}

int	conv2int(int n)
{
	int len;

	len = 0;
	if (n == -2147483648)
	{
		
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		len++;
		n = -n;
	}
	if (n > 9)
		len += conv2int(n / 10);
	ft_int2char(n % 10);
	len++;
	return (len);
}


int	conv2str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static void	ft_u2char(unsigned int i)
{
	char	c;

	c = (i + 48);
	write (1, &c, 1);
}

int	conv2u(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += conv2u(n / 10);
	ft_u2char(n % 10);
	len++;
	return (len);
}

static int	convertor2(va_list args, const char format)
{
	void	*ptr;
	int		len;

	ptr = va_arg(args, void*);
	len = 0;
	if (format == 'p')
	{
		write(1,"0x", 2);
		len = len + 2;
		len += conv2hexp((unsigned long)ptr, "0123456789abcdef");
	}
	if (format == 'x')
		len += conv2hexp((unsigned long)ptr, "0123456789abcdef");
	if (format == 'X')
		len += conv2hexp((unsigned long)ptr, "0123456789ABCDEF");
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
	int len;

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

int main ()
{
	int numero = 54;
	int ad = 92;
	char *str = "poussin";
	int *ptr = &ad;
	char c ='k';
	int x = 45;
	unsigned int u = 564564;

	int len1 = ft_printf("int = %i\nstr = %s\nptr = %p\nchar = %c \n100 = %% \n", ad, str, ptr, c);
	int len2 = printf("int = %i\nstr = %s\nptr = %p\nchar = %c \n100 = %% \n", ad, str, ptr, c);
	
	int len3 = ft_printf("%u\n%x\n%X", u, x, x);
	int len4 = printf("%u\n%x\n%X", u, x, x);
	printf("\n\n");
	printf("%d\n%d\n%d\n%d\n", len1, len2, len3, len4);
	return (0);
}
