#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux\mlx.h"
// # include "minilibx-linux\mlx_int.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_node	t_data;
struct	s_node
{
	void	*mlx;
	void	*win;
	char	**map;
	int		player_pos_x;
	int		player_pos_y;
	int		collects_left;
	void	*wall;
	void	*ground;
	void	*player;
	void	*collectable;
	void	*exit;
};

//key_presses
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

void *key_pressed(int keycode, t_data *game);
void move_player(t_data *game, int x, int y);

# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif
//put_sprite.c
void	load_images(t_data *game);
char	*render_image(t_data *game);
//map reader
char	*read_map(int fd);
char	**map_reader(int fd);
char	*assign_image(char **map);

// map validation
int	valid_map(int fd, char *result);
int h_border_check(char *line);
int v_border_check(char *line);
int	is_rectangle(char **map);
void check_double(char *line);

// exit function
int	close_game(t_data *game);
void free_map(char **map);

#endif