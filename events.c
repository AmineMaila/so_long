/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:32:19 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/17 22:58:20 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

void	draw_player(t_game_instance *game, int new_x, int new_y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->txt.player, new_x * DIMS, new_y * DIMS);
	if (game->draw_exit == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->txt.closed,
			game->pos.p_pos.x * DIMS, game->pos.p_pos.y * DIMS);
		game->draw_exit = 0;
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->txt.floor,
			game->pos.p_pos.x * DIMS, game->pos.p_pos.y * DIMS);
}

void	new_pos(t_game_instance *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == 'E' && game->exit_status == 1)
	{
		ft_printf("Moves : %d\n", ++game->obj.moves);
		ft_exit(5, game);
	}
	else if (game->map.matrix[new_y][new_x] != '1')
	{
		if (game->was_exit == 1)
		{
			game->map.matrix[game->pos.p_pos.y][game->pos.p_pos.x] = 'E';
			game->was_exit = 0;
			game->draw_exit = 1;
		}
		else
			game->map.matrix[game->pos.p_pos.y][game->pos.p_pos.x] = '0';
		if (game->map.matrix[new_y][new_x] == 'C')
			track_item(game);
		if (game->map.matrix[new_y][new_x] == 'E')
			game->was_exit = 1;
		game->map.matrix[new_y][new_x] = 'P';
		draw_player(game, new_x, new_y);
		ft_printf("Moves : %d\n", ++game->obj.moves);
		game->pos.p_pos.x = new_x;
		game->pos.p_pos.y = new_y;
	}
}

int	handle_input(int keysym, t_game_instance *game)
{
	if (keysym == UP || keysym == W)
		new_pos(game, game->pos.p_pos.x, game->pos.p_pos.y - 1);
	else if (keysym == DOWN || keysym == S)
		new_pos(game, game->pos.p_pos.x, game->pos.p_pos.y + 1);
	else if (keysym == RIGHT || keysym == D)
		new_pos(game, game->pos.p_pos.x + 1, game->pos.p_pos.y);
	else if (keysym == LEFT || keysym == A)
		new_pos(game, game->pos.p_pos.x - 1, game->pos.p_pos.y);
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
