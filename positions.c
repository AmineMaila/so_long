/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:06:19 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/17 22:05:59 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

void	track_item(t_game_instance *game)
{
	game->obj.item_count--;
	if (game->obj.item_count == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->txt.open,
			game->pos.e_pos.x * DIMS, game->pos.e_pos.y * DIMS);
		game->exit_status = 1;
	}
}

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
				game->pos.p_pos.x = j;
				game->pos.p_pos.y = i;
			}
			else if (game->map.matrix[i][j] == 'E')
			{
				game->pos.e_pos.x = j;
				game->pos.e_pos.y = i;
			}
			j++;
		}
		i++;
	}
}
