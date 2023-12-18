/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:11:20 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/17 22:03:27 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

void	obj_count(t_game_instance *game)
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
				game->obj.player_count++;
			else if (game->map.matrix[i][j] == 'C')
				game->obj.item_count++;
			else if (game->map.matrix[i][j] == 'E')
				game->obj.exit_count++;
			else if (game->map.matrix[i][j] == '0')
				game->obj.floor_count++;
			else if (game->map.matrix[i][j] != '1')
				ft_exit(3, game);
			j++;
		}
		i++;
	}
}

int	validate_obj_count(t_game_instance *game)
{
	obj_count(game);
	if (game->obj.player_count != 1)
		return (0);
	else if (game->obj.exit_count != 1)
		return (0);
	else if (game->obj.item_count < 1)
		return (0);
	else if (game->obj.floor_count < 1)
		return (0);
	return (1);
}

int	validate_walls(t_game_instance *game)
{
	int	i;
	int	last;

	i = 0;
	while (game->map.matrix[0][i])
	{
		if (game->map.matrix[0][i] != '1' ||
			game->map.matrix[game->map.height - 1][i] != '1')
			return (0);
		i++;
	}
	last = ft_strlen(game->map.matrix[0]) - 1;
	i = 1;
	while (i < game->map.height - 1)
	{
		if (game->map.matrix[i][0] != '1' || game->map.matrix[i][last] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_rectangular(t_game_instance *game)
{
	int	len;
	int	i;

	len = ft_strlen(game->map.matrix[0]);
	i = 1;
	while (game->map.matrix[i])
	{
		if (ft_strlen(game->map.matrix[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

void	is_map_valid(t_game_instance *game)
{
	if (!validate_obj_count(game))
		ft_exit(3, game);
	if (!is_map_rectangular(game))
		ft_exit(3, game);
	if (!validate_walls(game))
		ft_exit(3, game);
	if (!check_path(game))
		ft_exit(8, game);
}
