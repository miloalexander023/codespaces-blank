/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:08:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 15:08:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..\so_long.h"
#include "..\minilibx-linux\mlx.h"

void free_map(char **map)
{
	int i;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_game(t_data *game)
{
	free_map(game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}