/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:50:16 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/10 22:12:30 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	ft_putstr(char *s, int *pcount)
{
	if (s == NULL)
	{
		if (!ft_putstr("(null)", pcount))
			return (0);
		return (1);
	}
	while (*(s))
		if (!ft_putchar(*(s++), pcount))
			return (0);
	return (1);
}
