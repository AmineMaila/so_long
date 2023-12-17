/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:10:19 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/17 14:20:01 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	map_height(int fd)
{
	char	buffer[1024];
	int		bread;
	int		i;
	int		count;

	count = 0;
	bread = read(fd, buffer, 1023);
	if (bread == -1)
		return (0);
	while (bread > 0)
	{
		buffer[bread] = '\0';
		i = 0;
		while (buffer[i])
			if (buffer[i++] == '\n')
				count++;
		bread = read(fd, buffer, 1023);
		if (bread == -1)
			return (0);
	}
	count++;
	return (count);
}

int	open_map_height(char *filename)
{
	int	fd;
	int	count;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	count = map_height(fd);
	if (close(fd) == -1)
		return (0);
	return (count);
}

int	read_map(int fd, t_game_instance *game)
{
	int	i;

	game->map.matrix = malloc((game->map.height + 1) * sizeof(char *));
	if (!game->map.matrix)
		return (0);
	i = 0;
	while (i < game->map.height)
	{
		game->map.matrix[i] = get_next_line(fd);
		if (!game->map.matrix[i])
			break ;
		if (i != game->map.height - 1)
			game->map.matrix[i][ft_strlen(game->map.matrix[i]) - 1] = '\0';
		i++;
	}
	if (game->map.matrix[0] == NULL)
		return (0);
	game->map.width = ft_strlen(game->map.matrix[0]);
	game->map.height = i;
	game->map.matrix[i] = NULL;
	return (1);
}

int	map_extension(char *map_path)
{
	int	len;

	len = ft_strlen(map_path);
	if (len < 5)
		return (0);
	len -= 4;
	if (ft_strcmp(map_path + len, ".ber"))
		return (0);
	return (1);
}

void	ft_open_map(t_game_instance *game)
{
	int	fd;

	if (!map_extension(game->map.filename))
		ft_exit(1, game);
	fd = open(game->map.filename, O_RDONLY);
	if (fd == -1)
		ft_exit(1, game);
	game->map.height = open_map_height(game->map.filename);
	if (game->map.height < 3)
	{
		close(fd);
		ft_exit(1, game);
	}
	if (!read_map(fd, game))
	{
		close(fd);
		ft_exit(2, game);
	}
	close(fd);
	player_exit_pos(game);
	is_map_valid(game);
}
