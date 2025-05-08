/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:48:25 by marvin            #+#    #+#             */
/*   Updated: 2025/04/28 17:48:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..\so_long.h"
#include "..\..\libft\libft.h"
#include "..\minilibx-linux\mlx.h"
#include "..\minilibx-linux\mlx_int.h"

void	load_images(t_data *game)
{
	int img_widt;
	int img_height;

	game->wall = mlx_xpm_file_to_image(game->mlx, "red.xpm", &img_widt, &img_height);
	game->ground = mlx_xpm_file_to_image(game->mlx, "green.xpm", &img_widt, &img_height);
	game->player = mlx_xpm_file_to_image(game->mlx,  "purple.xpm", &img_widt, &img_height);
	game->collectable = mlx_xpm_file_to_image(game->mlx,  "yellow.xpm", &img_widt, &img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx,  "blue.xpm", &img_widt, &img_height);
}
char	*render_image(t_data *game)
{
	int x;
	int y;
	void *img;
	char tile;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			tile = game->map[x][y];
			img = NULL;
			if (tile == '1')
				printf("wall: ");
				// img = game->wall;
			else if (tile == '0')
				printf("ground: ");
				// img = game->ground;
			else if (tile == 'P')
			{
				printf("player: ");
				game->player_pos_x = x;
				game->player_pos_y = y;
				// img = game->player;
			}
			else if (tile == 'C')
			{
				printf("coin: ");
				game->collects_left += 1;
				// img = game->collectable;
			}
			else if (tile == 'E')
				printf("exit: ");			
				// img = game->exit;
			if (img != NULL)
				printf("%c\n", tile);
				// mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
			y++;
		}
		x++;
	}
}
