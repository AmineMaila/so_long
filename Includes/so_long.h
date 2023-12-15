/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:02:33 by mmaila            #+#    #+#             */
/*   Updated: 2023/12/14 23:29:39 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>

//
# define DIMS 32
# define BUFFER_SIZE 1024
# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"

// controls
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

// objects
# define COLLECTABLE 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define FLOOR '0'
# define WALL '1'

typedef struct	s_objects
{
	void	*collectable;
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*player_up;
	void	*exit;
	void	*floor;
	void	*wall;
}				t_objects;

typedef struct	s_count
{
	int	player_count;
	int	exit_count;
	int	collectable_count;
	int floor_count;
	int	moves;
}				t_count;

typedef struct	s_list
{
	void			*data;
	struct s_list   *next;
}				t_list;

typedef struct	s_coordinate
{
	int	x;
	int	y;
}				t_coordinate;

typedef struct	s_position
{
	t_coordinate	player_pos;
	t_coordinate	exit_pos;
}				t_position;

typedef struct	s_map
{
	char	*filename;
	int		width;
	int		height;
	char	**matrix;
}				t_map;

typedef struct	s_game_instance
{
	void			*mlx;
	void			*win;
	int				exit_status;
	t_list			*garbage;
	t_map			map;
	t_coordinate	coords;
	t_position		pos;
	t_count			obj;
	t_objects		txt;
}				t_game_instance;

// map
int		open_map_height(char *filename);
int		map_height(int fd);
int		read_map(int fd, t_game_instance *game);
int		map_extension(char *map_path);
void    ft_open_map(t_game_instance *game);

// error
void	free_matrix(t_game_instance *game);
void	ft_destroy_img(t_game_instance *game);
void	ft_exit(int n, t_game_instance *game);
void	cleanup(t_game_instance *game);

// libft
void	ft_lstadd_back(t_list **lst, void *data);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
t_list	*ft_lstnew(void *content);
void	del(void *data);
char	*ft_strcpy(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strncat(char *dest, const char *src, unsigned int nb);
int		ft_strcmp(char *s1, char *s2);

// get_next_line
char	*get_next_line(int fd);
char	*readfile(char	**chyata, char *buf, char **readbuf, int fd);
char	*chyatacheck(char *chyata, char **readbuf);
char	*package(char **chyata, char *buf, char *readbuf);
char	*ft_realloc(char *buf, int xtrsize);
int		newline(char *buf);

// printf
int		ft_prints(char c, va_list args, int *pcount);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c, int *pcount);
int		ft_putstr(char *s, int *pcount);
int		ft_putnbr(int n, int *pcount);
int		ft_putnbr_u(unsigned int n, int *pcount);
int		ft_putnbr_base(size_t nbr, char *base, int *pcount);

// draw
int		ft_draw(t_game_instance *game);
void	draw_image_type(t_game_instance *game);

// positions
void	check_obj_count(t_game_instance *game);
void	player_exit_pos(t_game_instance *game);

// events
int		handle_input(int keysym, t_game_instance *game);
void	ft_play(t_game_instance *game);

// map valid
void    is_map_valid(t_game_instance *game);
int		is_map_rectangular(t_game_instance *game);
int		validate_walls(t_game_instance *game);
int		validate_obj_count(t_game_instance *game);
void	obj_count(t_game_instance *game);

#endif