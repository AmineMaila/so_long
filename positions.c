/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:06:19 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/14 22:48:49 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

void	player_exit_pos(t_game_instance *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.matrix[i])
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (game->map.matrix[i][j] == 'P')
			{
				game->pos.player_pos.x = j;
				game->pos.player_pos.y = i;
			}
			else if (game->map.matrix[i][j] == 'E')
			{
				game->pos.exit_pos.x = j;
				game->pos.exit_pos.y = i;
			}
			j++;
		}
		i++;
	}
}
