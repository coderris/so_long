/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:59:36 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 12:00:16 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_gameplay_start(t_game_instance *game_init)
{
	mlx_hook(game_init->win_ptr, 17, 0, ft_exit_program, game_init);
	mlx_hook(game_init->win_ptr, 2, (1L << 0), ft_check_keyboard, game_init);
	mlx_loop_hook(game_init->mlx_ptr, &ft_map_draw, game_init);
}

int	ft_print_shell(t_game_instance *game_init)
{
	static int	previous_count_movements;
	int			current_count_movements;

	previous_count_movements = -1;
	current_count_movements = game_init->game_data.count_movements;
	if (current_count_movements != previous_count_movements)
	{
		ft_printf("You moved %d times.\n", current_count_movements);
		previous_count_movements = current_count_movements;
	}
	return (1);
}

int	ft_events_pressed(t_game_instance *game_init, int column, int row)
{
	int	new_row;
	int	new_col;
	int	current_tile;

	new_row = game_init->positions_init.player_row + row;
	new_col = game_init->positions_init.player_col + column;
	if (new_row < 0 || new_row >= game_init->map_init.rows_matrice
		|| new_col < 0 || new_col >= game_init->map_init.cols_matrice)
		return (ft_print_shell(game_init));
	current_tile = game_init->map_init.matrice[new_row][new_col];
	if (current_tile == EMPTY || current_tile == COLLECTIBLE)
		ft_handle_movement(game_init, new_row, new_col, current_tile);
	else if (current_tile == EXIT
		&& game_init->game_data.count_collectible == 0)
		ft_win(game_init);
	return (ft_print_shell(game_init));
}

void	ft_handle_movement(t_game_instance *game_init, int new_row,
	int new_col, int current_tile)
{
	game_init->map_init.matrice[new_row][new_col] = PLAYER;
	game_init->map_init.matrice[game_init->positions_init.player_row]
	[game_init->positions_init.player_col] = EMPTY;
	game_init->positions_init.player_row = new_row;
	game_init->positions_init.player_col = new_col;
	if (current_tile == COLLECTIBLE)
		game_init->game_data.count_collectible--;
	game_init->game_data.count_movements++;
}

void	ft_locate_player(t_game_instance *game_init)
{
	int	col;
	int	row;

	row = 0;
	while (row < game_init->map_init.rows_matrice)
	{
		col = 0;
		while (col < game_init->map_init.cols_matrice)
		{
			if (game_init->map_init.matrice[row][col] == PLAYER)
			{
				game_init->positions_init.player_row = row;
				game_init->positions_init.player_col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}
