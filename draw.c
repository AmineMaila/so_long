/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:54:24 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/14 23:07:55 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

void	draw_image_type(t_game_instance *game)
{
	int	i;
	int	j;

	i = game->coords.y / DIMS;
	j = game->coords.x / DIMS;
	if (game->map.matrix[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->txt.wall, game->coords.x, game->coords.y);
	else if (game->map.matrix[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->txt.exit, game->coords.x, game->coords.y);
	else if (game->map.matrix[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->txt.floor, game->coords.x, game->coords.y);
		mlx_put_image_to_window(game->mlx, game->win, game->txt.collectable, game->coords.x, game->coords.y);
	}
	else if (game->map.matrix[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->txt.floor, game->coords.x, game->coords.y);
		mlx_put_image_to_window(game->mlx, game->win, game->txt.player, game->coords.x, game->coords.y);
	}
	else if (game->map.matrix[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->txt.floor, game->coords.x, game->coords.y);
}

int	ft_draw(t_game_instance *game)
{
	game->coords.y = 0;
	while (game->coords.y < game->map.height * DIMS)
	{
		game->coords.x = 0;
		while (game->coords.x < game->map.width * DIMS)
		{
			draw_image_type(game);
			game->coords.x += DIMS;
		}
		game->coords.y += DIMS;
	}
	return (0);
}


