/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:13:13 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/16 18:38:11 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	check_map(char ***tab)
{
	int	i;
	int	j;

	i = 0;
	while ((*tab)[i])
	{
		j = 0;
		while ((*tab)[i][j])
		{
			if ((*tab)[i][j] == 'C' || (*tab)[i][j] == 'E')
			{
				free_matrix(tab);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_matrix(tab);
	return (1);
}

void	flood_fill(char ***tab, int x, int y)
{
	if ((*tab)[y][x] != '1' && (*tab)[y][x] != 'F')
	{
		(*tab)[y][x] = 'F';
		flood_fill(tab, x + 1, y);
		flood_fill(tab, x - 1, y);
		flood_fill(tab, x, y + 1);
		flood_fill(tab, x, y - 1);
	}
}

int	check_path(t_game_instance *game)
{
	int		i;
	int		j;
	int		len;
	char	**matrix_cpy;

	i = 0;
	while (game->map.matrix[i])
		i++;
	matrix_cpy = malloc((i + 1) * sizeof(char *));
	i = 0;
	len = ft_strlen(game->map.matrix[0]);
	while (game->map.matrix[i])
	{
		j = 0;
		matrix_cpy[i] = malloc(len + 1);
		while (game->map.matrix[i][j])
		{
			matrix_cpy[i][j] = game->map.matrix[i][j];
			j++;
		}
		matrix_cpy[i++][j] = '\0';
	}
	matrix_cpy[i] = NULL;
	flood_fill(&matrix_cpy, game->pos.player_pos.x, game->pos.player_pos.y);
	return (check_map(&matrix_cpy));
}
