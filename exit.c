/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:06:10 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/17 00:40:39 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

void	free_matrix(char ***matrix)
{
	int	i;

	i = 0;
	while ((*matrix)[i])
		free((*matrix)[i++]);
	free((*matrix));
}

void	ft_destroy_img(t_game_instance *game)
{
	if (game->txt.item)
		mlx_destroy_image(game->mlx, game->txt.item);
	if (game->txt.player)
		mlx_destroy_image(game->mlx, game->txt.player);
	if (game->txt.closed)
		mlx_destroy_image(game->mlx, game->txt.closed);
	if (game->txt.open)
		mlx_destroy_image(game->mlx, game->txt.open);
	if (game->txt.floor)
		mlx_destroy_image(game->mlx, game->txt.floor);
	if (game->txt.wall)
		mlx_destroy_image(game->mlx, game->txt.wall);
}

void	cleanup(t_game_instance *game)
{
	ft_destroy_img(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	ft_lstclear(&game->garbage);
	if (game->map.matrix)
		free_matrix(&game->map.matrix);
}

void	ft_exit(int n, t_game_instance *game)
{
	if (n == 1)
		ft_printf("%sError\nA valid <map>.ber was not submitted!\n", COLOR_RED);
	else if (n == 2)
		ft_printf("%sError\nAllocation Failed!\n", COLOR_RED);
	else if (n == 3)
		ft_printf("%sError\nThe map provided did not meet the requirements!\n",
			COLOR_RED);
	else if (n == 5)
		ft_printf("%sYou Won!\n", COLOR_GREEN);
	else if (n == 7)
		ft_printf("%sError\nCould not create image!\n", COLOR_RED);
	else if (n == 8)
		ft_printf("%sError\nMap does not have a valid path\n", COLOR_RED);
	cleanup(game);
	exit(n);
}

int	press_x(t_game_instance *game)
{
	ft_exit(0, game);
	return (0);
}
