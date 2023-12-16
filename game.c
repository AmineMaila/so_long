/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:42:28 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/16 20:06:38 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"
#include <stdio.h>

void	make_image(void **txt, char *path, t_game_instance *game)
{
	int	d1;
	int	d2;

	*txt = mlx_xpm_file_to_image(game->mlx, path, &d1, &d2);
	if (!(*txt))
		ft_exit(7, game);
}

void	init_img(t_game_instance *game)
{
	make_image(&game->txt.item, "textures/Key.xpm", game);
	make_image(&game->txt.down, "textures/_down.xpm", game);
	make_image(&game->txt.up, "textures/_up.xpm", game);
	make_image(&game->txt.left, "textures/_left.xpm", game);
	make_image(&game->txt.right, "textures/_right.xpm", game);
	make_image(&game->txt.exit, "textures/Hatch1.xpm", game);
	make_image(&game->txt.floor, "textures/Floor.xpm", game);
	make_image(&game->txt.wall, "textures/Wall.xpm", game);
}

void	game_init(t_game_instance *game)
{
	game->txt.item = NULL;
	game->txt.down = NULL;
	game->txt.up = NULL;
	game->txt.left = NULL;
	game->txt.right = NULL;
	game->txt.exit = NULL;
	game->txt.floor = NULL;
	game->txt.wall = NULL;
	game->garbage = NULL;
	game->win = NULL;
	game->map.matrix = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit(2, game);
	ft_lstadd_back(&game->garbage, game->mlx);
	game->obj.player_count = 0;
	game->obj.exit_count = 0;
	game->obj.moves = 0;
	game->obj.item_count = 0;
	game->exit_status = 0;
	init_img(game);
}

void	a()
{
	system("leaks Dungeon_Mage");
}

int	main(int argc, char *argv[])
{
	t_game_instance	game;

	atexit(a);
	game_init(&game);
	if (argc != 2)
		ft_exit(1, &game);
	game.map.filename = argv[1];
	game.argv_tmp = argv;
	ft_open_map(&game);
	game.win = mlx_new_window(game.mlx, game.map.width * DIMS,
			game.map.height * DIMS, "Dungeon Mage");
	if (!game.win)
		ft_exit(2, &game);
	ft_play(&game);
	mlx_loop(game.mlx);
}
