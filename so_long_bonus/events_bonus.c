/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:32:19 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/18 01:04:43 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	draw_player(t_game_instance *game, int new_x, int new_y)
{
	if (new_x > game->pos.p_pos.x)
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.right, new_x * DIMS, new_y * DIMS);
	else if (new_x < game->pos.p_pos.x)
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.left, new_x * DIMS, new_y * DIMS);
	else if (new_y > game->pos.p_pos.y)
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.player, new_x * DIMS, new_y * DIMS);
	else if (new_y < game->pos.p_pos.y)
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.up, new_x * DIMS, new_y * DIMS);
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

int	write_to_display(t_game_instance *game)
{
	char	*arr;
	char	*moves;

	game->obj.moves++;
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
		write_to_display(game);
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
	write_to_display(game);
	mlx_hook(game->win, 17, 0, press_x, game);
	mlx_key_hook(game->win, handle_input, game);
}
