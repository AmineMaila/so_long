/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:04:24 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/10 22:11:29 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	intspecifier(char c, va_list args, int *pcount)
{
	int	x;

	if (c == '%')
	{
		if (!ft_putchar('%', pcount))
			return (0);
	}
	else if (c == 'c')
	{
		x = va_arg(args, int);
		if (!ft_putchar(x, pcount))
			return (0);
	}
	else if (c == 'd' || c == 'i')
	{
		x = va_arg(args, int);
		if (!ft_putnbr(x, pcount))
			return (0);
	}
	return (1);
}

static int	size_tspecifier(char c, va_list args, int *pcount)
{
	size_t	p;

	if (c == 'p')
	{
		p = va_arg(args, size_t);
		if (!ft_putstr("0x", pcount))
			return (0);
		if (!ft_putnbr_base(p, "0123456789abcdef", pcount))
			return (0);
	}
	return (1);
}

static int	uintspecifier(char c, va_list args, int *pcount)
{
	unsigned int	u;

	if (c == 'u')
	{
		u = va_arg(args, unsigned int);
		if (!ft_putnbr_u(u, pcount))
			return (0);
	}
	else if (c == 'x')
	{
		u = va_arg(args, unsigned int);
		if (!ft_putnbr_base(u, "0123456789abcdef", pcount))
			return (0);
	}
	else if (c == 'X')
	{
		u = va_arg(args, unsigned int);
		if (!ft_putnbr_base(u, "0123456789ABCDEF", pcount))
			return (0);
	}
	return (1);
}

static int	charspecifier(char c, va_list args, int *pcount)
{
	char	*s;

	if (c == 's')
	{
		s = va_arg(args, char *);
		if (!ft_putstr(s, pcount))
			return (0);
	}
	return (1);
}

int	ft_prints(char c, va_list args, int *pcount)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == '%')
	{
		if (!intspecifier(c, args, pcount))
			return (0);
		return (1);
	}
	else if (c == 's')
	{
		if (!charspecifier(c, args, pcount))
			return (0);
		return (1);
	}
	else if (c == 'p')
	{
		if (!size_tspecifier(c, args, pcount))
			return (0);
		return (1);
	}
	else if (c == 'u' || c == 'x' || c == 'X')
	{
		if (!uintspecifier(c, args, pcount))
			return (0);
		return (1);
	}
	return (2);
}
