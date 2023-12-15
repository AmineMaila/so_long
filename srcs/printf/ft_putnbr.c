/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:04:44 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/10 22:11:58 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	printnb(int n, int *pcount)
{
	if (n >= 10 || n <= -10)
		if (!printnb(n / 10, pcount))
			return (0);
	if (n < 0)
	{
		if (!ft_putchar(((n % 10) * -1) + '0', pcount))
			return (0);
	}
	else
	{
		if (!ft_putchar((n % 10) + '0', pcount))
			return (0);
	}
	return (1);
}

int	ft_putnbr(int n, int *pcount)
{
	if (n < 0)
	{
		if (!ft_putchar('-', pcount))
			return (0);
	}
	if (!printnb(n, pcount))
		return (0);
	return (1);
}
