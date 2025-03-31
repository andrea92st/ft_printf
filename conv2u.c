/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:49:45 by fio               #+#    #+#             */
/*   Updated: 2025/03/31 11:25:00 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
