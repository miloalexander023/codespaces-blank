#include "..\so_long.h"

void *key_pressed(int keycode, t_data *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
}

void move_player(t_data *game, int x, int y)
{
	int new_x;
	int new_y;
	char next_tile;

	new_x = game->player_pos_x + x;
	new_y = game->player_pos_y + y;
	next_tile = game->map[new_x][new_y];
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
	{
		game->collects_left--;
		game->map[new_x][new_y] = '0';
	}
	if (next_tile == 'E')
	{
		if (game->collects_left == 0)
			close_game(game);
		return ;
	}
	game->player_pos_x = new_x;
	game->player_pos_y = new_y;
	render_image(game);
}