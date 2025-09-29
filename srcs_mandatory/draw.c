/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:59:05 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 11:40:55 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_map_draw(t_game_instance *game_init)
{
	int	row;
	int	column;

	row = 0;
	while (row < game_init->map_init.rows_matrice)
	{
		column = 0;
		while (column < game_init->map_init.cols_matrice)
		{
			ft_draw_tile(game_init, row, column);
			column++;
		}
		row++;
	}
	return (0);
}

void	ft_draw_tile(t_game_instance *game_init, int row, int column)
{
	char	tile;

	tile = game_init->map_init.matrice[row][column];
	if (tile == WALL)
		ft_set(game_init, game_init->game_objs.wall, column, row);
	else if (tile == EMPTY)
		ft_set(game_init, game_init->game_objs.floor, column, row);
	else if (tile == PLAYER)
		ft_set(game_init, game_init->game_objs.player, column, row);
	else if (tile == COLLECTIBLE)
		ft_set(game_init, game_init->game_objs.collectible, column, row);
	else if (tile == EXIT)
		ft_draw_exit(game_init, column, row);
}

void	ft_draw_exit(t_game_instance *game_init, int column, int row)
{
	if (game_init->game_data.count_collectible == 0)
		ft_set(game_init, game_init->game_objs.exit_open, column, row);
	else
		ft_set(game_init, game_init->game_objs.exit_close, column, row);
}

void	ft_set(t_game_instance *game_init, void *img, int wid, int hgt)
{
	mlx_put_image_to_window(game_init->mlx_ptr, game_init->win_ptr,
		img, wid * CELL_SIZE, hgt * CELL_SIZE);
}
