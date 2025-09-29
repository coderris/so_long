/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:00:16 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 12:00:16 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdlib.h>

int	ft_is_valid_map(t_game_instance *game_init)
{
	int result;
	
	if (!(ft_is_map_shape_valid(game_init)))
		return (-4);
	result = ft_count_map_objects(game_init);
	if (result <= 0)
		return (result);
	if (!(ft_is_wall(game_init)))
		return (-16);
	if (!(ft_is_map_resoluble(game_init)))
		return (-18);
	return (1);
}

int	ft_count_map_objects(t_game_instance *game_init)
{
	if (!game_init || !game_init->map_init.matrice)
		return (0);
	ft_init_counters(game_init);
	return (ft_process_map_chars(game_init));
}

void	ft_init_counters(t_game_instance *game_init)
{
	game_init->game_data.count_player = 0;
	game_init->game_data.count_exit = 0;
	game_init->game_data.count_collectible = 0;
	game_init->game_data.count_wall = 0;
	game_init->game_data.count_empty = 0;
}

int	ft_process_map_chars(t_game_instance *game_init)
{
	int		row;
	int		column;
	int		result;

	row = 0;
	while (row < game_init->map_init.rows_matrice)
	{
		column = 0;
		while (column < game_init->map_init.cols_matrice)
		{
			result = ft_count_char(game_init, 
				game_init->map_init.matrice[row][column]);
			if (result < 0)
				return (result);
			column++;
		}
		row++;
	}
	return (ft_have_requires(game_init));
}

int	ft_count_char(t_game_instance *game_init, char c)
{
	if (c == PLAYER)
		game_init->game_data.count_player++;
	else if (c == EXIT)
		game_init->game_data.count_exit++;
	else if (c == COLLECTIBLE)
		game_init->game_data.count_collectible++;
	else if (c == WALL)
		game_init->game_data.count_wall++;
	else if (c == EMPTY)
		game_init->game_data.count_empty++;
	else
		return (-17);
	return (1);
}

int	ft_is_map_shape_valid(t_game_instance *game_init)
{
	int	ref_len;

	if (!game_init || !game_init->map_init.matrice)
		return (0);
	if (game_init->map_init.rows_matrice <= 0)
		return (0);
	ref_len = ft_get_row_length(game_init, 0);
	if (ref_len <= 0)
		return (0);
	return (ft_check_all_rows_length(game_init, ref_len));
}

int	ft_check_all_rows_length(t_game_instance *game_init, int ref_len)
{
	int	i;
	int	current_len;

	i = 0;
	while (i < game_init->map_init.rows_matrice)
	{
		current_len = ft_get_row_length(game_init, i);
		if (current_len != ref_len)
			return (0);
		i++;
	}
	game_init->map_init.cols_matrice = ref_len;
	return (1);
}

int	ft_get_row_length(t_game_instance *game_init, int row)
{
	int	j;
	int	row_len;

	row_len = 0;
	j = 0;
	while (game_init->map_init.matrice[row][j]
		&& game_init->map_init.matrice[row][j] != '\n')
	{
		row_len++;
		j++;
	}
	return (row_len);
}

int	ft_is_wall(t_game_instance *game_init)
{
	int		i;
	int		j;

	i = 0;
	while (i < game_init->map_init.rows_matrice)
	{
		j = 0;
		while (j < game_init->map_init.cols_matrice)
		{
			if (i == 0 || j == 0 || i == game_init->map_init.rows_matrice - 1
				|| j == game_init->map_init.cols_matrice - 1)
			{
				if (game_init->map_init.matrice[i][j] != WALL)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_have_requires(t_game_instance *game_init)
{
	if (game_init->game_data.count_player == 0)
		return (-10);
	if (game_init->game_data.count_player > 1)
		return (-14);
	if (game_init->game_data.count_exit == 0)
		return (-11);
	if (game_init->game_data.count_exit > 1)
		return (-15);
	if (game_init->game_data.count_collectible < 1)
		return (-13);
	return (1);
}
