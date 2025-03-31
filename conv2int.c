/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:17:54 by fio               #+#    #+#             */
/*   Updated: 2025/03/31 12:03:15 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_int2char(int i)
{
	char	c;

	c = (i + 48);
	write (1, &c, 1);
}

int	conv2int(int n)
{
	int	len;

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
