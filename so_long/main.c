/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:26:39 by marvin            #+#    #+#             */
/*   Updated: 2025/04/18 19:26:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.codam\get_next_line.h"
#include "minilibx-linux\mlx.h"
int main(void)
{
	t_data game;
	int		fd = open("maps+valid/map.ber", O_RDONLY);

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 20 * 64, 12 * 64, "so_long");
	game.map = map_reader(fd);
	// load_images(&game);
	render_image(&game);
	mlx_hook(game.win, 2, 1L<<0, key_pressed, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	// int	check;
	// check = valid_map(fd, result);
	// if (check == 1)
	// 	printf("map valid!\n");
	// if (check == 0)
	// 	printf("map not valid!\n");

	return (0);
}
// 	void *mlx;
// 	void *win;

// 	mlx = mlx_init();
// 	if (!mlx)
// 		return (1);
// 	win = mlx_new_window(mlx, 800, 600, "so_long_window");
// 	if (!win)
// 		return (1);
// 	// mlx_new_image()
// 	mlx_loop(mlx);
// }