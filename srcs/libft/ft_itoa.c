/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:34:01 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/15 17:06:23 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static void	populate(int n, char *arr, int count)
{
	if (n >= 10 || n <= -10)
		populate(n / 10, arr, count - 1);
	if (n < 0)
		arr[count] = ((n % 10) * -1) + '0';
	else
		arr[count] = (n % 10) + '0';
}

static int	arrsize(int n)
{
	int	temp;
	int	i;

	i = 1;
	temp = n;
	while (temp >= 10 || temp <= -10)
	{
		temp /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		size;

	size = arrsize(n);
	if (n < 0)
		size++;
	arr = (char *) malloc(size + 1);
	if (arr == NULL)
		return (NULL);
	if (n < 0)
		arr[0] = '-';
	populate (n, arr, size - 1);
	arr[size] = '\0';
	return (arr);
}
