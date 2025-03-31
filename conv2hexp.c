/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2hexp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:58:02 by fio               #+#    #+#             */
/*   Updated: 2025/03/31 12:03:04 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv2hexp(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += conv2hexp(n / 16, base);
	ft_putchar(base[n % 16]);
	len++;
	return (len);
}
