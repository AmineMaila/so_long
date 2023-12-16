/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:32:19 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/16 20:04:35 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	draw_player(t_game_instance *game, int new_x, int new_y)
{
	if (new_x > game->pos.player_pos.x)
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.right, new_x * DIMS, new_y * DIMS);
	else if (new_x < game->pos.player_pos.x)
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.left, new_x * DIMS, new_y * DIMS);
	else if (new_y > game->pos.player_pos.y)
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.down, new_x * DIMS, new_y * DIMS);
	else if (new_y < game->pos.player_pos.y)
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.up, new_x * DIMS, new_y * DIMS);
	mlx_put_image_to_window(game->mlx, game->win, game->txt.floor,
		game->pos.player_pos.x * DIMS, game->pos.player_pos.y * DIMS);
}

int	write_to_display(t_game_instance *game)
{
	char	*arr;
	char	*moves;

	game->coords.x = 0;
	while (game->coords.x / 32 < 6)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.wall, game->coords.x, 0);
		game->coords.x += 32;
	}
	moves = ft_itoa(game->obj.moves);
	if (!moves)
		ft_exit(2, game);
	arr = malloc(8 + ft_strlen(moves) + 1);
	if (!arr)
		ft_exit(2, game);
	arr = ft_strcpy(arr, "Moves : ");
	arr = ft_strcat(arr, moves);
	mlx_string_put(game->mlx, game->win, 3, 5, 0xFFFFFF, arr);
	free(arr);
	free(moves);
	return (0);
}

void	new_pos(t_game_instance *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == 'E' && game->exit_status == 1)
		ft_exit(5, game);
	else if (game->map.matrix[new_y][new_x] == 'M')
		ft_exit(13, game);
	else if (game->map.matrix[new_y][new_x] != '1' &&
		game->map.matrix[new_y][new_x] != 'E')
	{
		if (game->map.matrix[new_y][new_x] == 'C')
			game->obj.item_count--;
		game->map.matrix[new_y][new_x] = 'P';
		game->map.matrix[game->pos.player_pos.y][game->pos.player_pos.x] = '0';
		draw_player(game, new_x, new_y);
		write_to_display(game);
		game->obj.moves++;
		game->pos.player_pos.x = new_x;
		game->pos.player_pos.y = new_y;
	}
}

int	handle_input(int keysym, t_game_instance *game)
{
	if (game->obj.item_count == 0)
		game->exit_status = 1;
	if (keysym == UP)
		new_pos(game, game->pos.player_pos.x, game->pos.player_pos.y - 1);
	else if (keysym == DOWN)
		new_pos(game, game->pos.player_pos.x, game->pos.player_pos.y + 1);
	else if (keysym == RIGHT)
		new_pos(game, game->pos.player_pos.x + 1, game->pos.player_pos.y);
	else if (keysym == LEFT)
		new_pos(game, game->pos.player_pos.x - 1, game->pos.player_pos.y);
	else if (keysym == RESET)
	{
		cleanup(game);
		main(2, game->argv_tmp);
	}
	else if (keysym == ESC)
		ft_exit(0, game);
	return (0);
}

void	ft_play(t_game_instance *game)
{
	ft_draw(game);
	write_to_display(game);
	game->obj.moves++;
	mlx_hook(game->win, 17, 0, press_x, game);
	mlx_key_hook(game->win, handle_input, game);
}