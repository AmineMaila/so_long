/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:51:26 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/10 22:29:08 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	ft_lstdelone(t_list *lst)
{
	if (lst == NULL)
		return ;
	del(lst->data);
	free(lst);
	lst = NULL;
}
