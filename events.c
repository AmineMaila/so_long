/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:32:19 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/14 22:50:26 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

void	draw_player(t_game_instance *game, int new_x, int new_y)
{
	if (new_x > game->pos.player_pos.x)
		mlx_put_image_to_window(game->mlx, game->win, game->txt.player_right, new_x * DIMS, new_y * DIMS);
	else if (new_x < game->pos.player_pos.x)
		mlx_put_image_to_window(game->mlx, game->win, game->txt.player_left, new_x * DIMS, new_y * DIMS);
	else if (new_y > game->pos.player_pos.y)
		mlx_put_image_to_window(game->mlx, game->win, game->txt.player, new_x * DIMS, new_y * DIMS);
	else if (new_y < game->pos.player_pos.y)
		mlx_put_image_to_window(game->mlx, game->win, game->txt.player_up, new_x * DIMS, new_y * DIMS);
	mlx_put_image_to_window(game->mlx, game->win, game->txt.floor,
	game->pos.player_pos.x * DIMS, game->pos.player_pos.y * DIMS);
}

void	new_pos(t_game_instance *game, int x, int y)
{
	int new_x;
	int new_y;

	new_x = game->pos.player_pos.x + x;
	new_y = game->pos.player_pos.y + y;
	if (game->map.matrix[new_y][new_x] == 'E' && game->exit_status == 1)
		ft_exit(5, game);
	else if (game->map.matrix[new_y][new_x] != '1' && game->map.matrix[new_y][new_x] != 'E')
	{
		if (game->map.matrix[new_y][new_x] == 'C')
			game->obj.collectable_count--;
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
	if (game->obj.collectable_count == 0)
		game->exit_status = 1;
	if (keysym == UP)
		new_pos(game, 0, -1);
	else if (keysym == DOWN)
		new_pos(game, 0, 1);
	else if (keysym == RIGHT)
		new_pos(game, 1, 0);
	else if (keysym == LEFT)
		new_pos(game, -1, 0);
	return (0);
}

void	ft_play(t_game_instance *game)
{
	player_exit_pos(game);
	ft_draw(game);
	ft_printf("Moves : %d\n", game->obj.moves);
	mlx_key_hook(game->win, handle_input, game);
}
