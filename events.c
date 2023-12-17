/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:32:19 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/17 15:08:46 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

void	draw_player(t_game_instance *game, int new_x, int new_y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->txt.player, new_x * DIMS, new_y * DIMS);
	mlx_put_image_to_window(game->mlx, game->win, game->txt.floor,
		game->pos.player_pos.x * DIMS, game->pos.player_pos.y * DIMS);
}

void	new_pos(t_game_instance *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == 'E' && game->exit_status == 1)
	{
		ft_printf("Moves : %d\n", ++game->obj.moves);
		ft_exit(5, game);
	}
	else if (game->map.matrix[new_y][new_x] != '1' &&
		game->map.matrix[new_y][new_x] != 'E')
	{
		if (game->map.matrix[new_y][new_x] == 'C')
		{
			game->obj.item_count--;
			if (game->obj.item_count == 0)
			{
				mlx_put_image_to_window(game->mlx, game->win, game->txt.open,
					game->pos.exit_pos.x * DIMS, game->pos.exit_pos.y * DIMS);
				game->exit_status = 1;
			}
		}
		game->map.matrix[new_y][new_x] = 'P';
		game->map.matrix[game->pos.player_pos.y][game->pos.player_pos.x] = '0';
		draw_player(game, new_x, new_y);
		ft_printf("Moves : %d\n", ++game->obj.moves);
		game->pos.player_pos.x = new_x;
		game->pos.player_pos.y = new_y;
	}
}

int	handle_input(int keysym, t_game_instance *game)
{
	if (keysym == UP || keysym == W)
		new_pos(game, game->pos.player_pos.x, game->pos.player_pos.y - 1);
	else if (keysym == DOWN || keysym == S)
		new_pos(game, game->pos.player_pos.x, game->pos.player_pos.y + 1);
	else if (keysym == RIGHT || keysym == D)
		new_pos(game, game->pos.player_pos.x + 1, game->pos.player_pos.y);
	else if (keysym == LEFT || keysym == A)
		new_pos(game, game->pos.player_pos.x - 1, game->pos.player_pos.y);
	else if (keysym == ESC)
		ft_exit(0, game);
	return (0);
}

void	ft_play(t_game_instance *game)
{
	ft_draw(game);
	ft_printf("Moves : %d\n", game->obj.moves);
	mlx_hook(game->win, 17, 0, press_x, game);
	mlx_key_hook(game->win, handle_input, game);
}
