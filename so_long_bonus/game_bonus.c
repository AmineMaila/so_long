/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:42:28 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/18 15:30:49 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

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
	make_image(&game->txt.item, "../textures/Key.xpm", game);
	make_image(&game->txt.player, "../textures/player.xpm", game);
	make_image(&game->txt.up, "../textures/_up_bonus.xpm", game);
	make_image(&game->txt.left, "../textures/_left_bonus.xpm", game);
	make_image(&game->txt.right, "../textures/_right_bonus.xpm", game);
	make_image(&game->txt.closed, "../textures/closed.xpm", game);
	make_image(&game->txt.open, "../textures/open.xpm", game);
	make_image(&game->txt.floor, "../textures/Floor.xpm", game);
	make_image(&game->txt.wall, "../textures/Wall.xpm", game);
	make_image(&game->txt.enemy, "../textures/Enemy_bonus.xpm", game);
	make_image(&game->txt.e_left, "../textures/e_left.xpm", game);
	make_image(&game->txt.e_right, "../textures/e_right.xpm", game);
}

void	game_init(t_game_instance *game)
{
	game->txt.enemy = NULL;
	game->txt.e_left = NULL;
	game->txt.e_right = NULL;
	game->txt.item = NULL;
	game->txt.player = NULL;
	game->txt.up = NULL;
	game->txt.left = NULL;
	game->txt.right = NULL;
	game->txt.closed = NULL;
	game->txt.open = NULL;
	game->txt.floor = NULL;
	game->txt.wall = NULL;
	game->win = NULL;
	game->map.matrix = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit(2, game);
	game->obj.player_count = 0;
	game->obj.exit_count = 0;
	game->obj.moves = -1;
	game->obj.item_count = 0;
	game->exit_status = 0;
	game->was_exit = 0;
	game->draw_exit = 0;
	init_img(game);
}

int	main(int argc, char *argv[])
{
	t_game_instance	game;

	game_init(&game);
	if (argc != 2)
		ft_exit(1, &game);
	game.map.filename = argv[1];
	ft_open_map(&game);
	game.win = mlx_new_window(game.mlx, game.map.width * DIMS,
			game.map.height * DIMS, "Dungeon Mage");
	if (!game.win)
		ft_exit(2, &game);
	ft_play(&game);
	mlx_loop(game.mlx);
}
