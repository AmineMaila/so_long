/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:06:10 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/14 23:33:22 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

void	free_matrix(t_game_instance *game)
{
	int	i;

	i = 0;
	while (game->map.matrix[i])
		free(game->map.matrix[i++]);
	free(game->map.matrix);
}

void	ft_destroy_img(t_game_instance *game)
{
	if (game->txt.collectable)
		mlx_destroy_image(game->mlx, game->txt.collectable);
	if (game->txt.player)
		mlx_destroy_image(game->mlx, game->txt.player);
	if (game->txt.player_up)
		mlx_destroy_image(game->mlx, game->txt.player_up);
	if (game->txt.player_left)
		mlx_destroy_image(game->mlx, game->txt.player_left);
	if (game->txt.player_right)
		mlx_destroy_image(game->mlx, game->txt.player_right);
	if (game->txt.exit)
		mlx_destroy_image(game->mlx, game->txt.exit);
	if (game->txt.floor)
		mlx_destroy_image(game->mlx, game->txt.floor);
	if (game->txt.wall)
		mlx_destroy_image(game->mlx, game->txt.wall);
}

void	cleanup(t_game_instance *game)
{
	ft_lstclear(&game->garbage);
	ft_destroy_img(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map.matrix)
		free_matrix(game);
}

void	ft_exit(int n, t_game_instance *game)
{
	if (n == 1)
		ft_printf("%sError\nA valid <map>.ber was not submitted!\n", COLOR_RED);
	else if (n == 2)
		ft_printf("%sError\nAllocation Failed!\n", COLOR_RED);
	else if (n == 3)
		ft_printf("%sError\nThe map provided did not meet the requirements!\n", COLOR_RED);
	else if (n == 5)
		ft_printf("%sYou Won!\n", COLOR_GREEN);
	else if (n == 7)
		ft_printf("%sError\nCould not create image!\n", COLOR_RED);
	cleanup(game);
	exit(n);
}