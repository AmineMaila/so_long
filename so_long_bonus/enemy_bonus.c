/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:06:06 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/18 15:18:10 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	draw_enemy(t_game_instance *game, int new_x)
{
	if (new_x > game->pos.m_pos.x)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->txt.floor,
			game->pos.m_pos.x * DIMS, game->pos.m_pos.y * DIMS);
		mlx_put_image_to_window(game->mlx, game->win, game->txt.e_right,
			new_x * DIMS, game->pos.m_pos.y * DIMS);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->txt.floor,
			game->pos.m_pos.x * DIMS, game->pos.m_pos.y * DIMS);
		mlx_put_image_to_window(game->mlx, game->win, game->txt.e_left,
			new_x * DIMS, game->pos.m_pos.y * DIMS);
	}
}

void	move(t_game_instance *game, int new_x)
{
	if (new_x == game->pos.e_pos.x && game->pos.m_pos.y == game->pos.e_pos.y)
	{
		game->move *= -1;
		return ;
	}
	if (game->map.matrix[game->pos.m_pos.y][new_x] == 'P')
		ft_exit(13, game);
	if (game->map.matrix[game->pos.m_pos.y][new_x] != '1'
	&& game->map.matrix[game->pos.m_pos.y][new_x] != 'C')
	{
		game->map.matrix[game->pos.m_pos.y][new_x] = 'M';
		game->map.matrix[game->pos.m_pos.y][game->pos.m_pos.x] = '0';
		draw_enemy(game, new_x);
	}
	else
		game->move *= -1;
}

int	move_enemy(t_game_instance *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.matrix[i])
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (game->map.matrix[i][j] == 'M')
			{
				game->pos.m_pos.x = j;
				game->pos.m_pos.y = i;
				if (game->move > 0)
					move(game, game->pos.m_pos.x + 1);
				else
					move(game, game->pos.m_pos.x - 1);
				j++;
			}
			j++;
		}
		i++;
	}
	return (0);
}
