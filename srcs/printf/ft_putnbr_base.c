/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:59:11 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/10 22:22:26 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	print_nbr(size_t nb, char *base, size_t baselen, int *pcount)
{
	if (nb >= baselen)
	{
		if (!print_nbr(nb / baselen, base, baselen, pcount))
			return (0);
	}
	if (!ft_putchar(base[nb % baselen], pcount))
		return (0);
	return (1);
}

int	ft_putnbr_base(size_t nbr, char *base, int *pcount)
{
	int	baselen;

	baselen = ft_strlen(base);
	if (!print_nbr(nbr, base, baselen, pcount))
		return (0);
	return (1);
}
