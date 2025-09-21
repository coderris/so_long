/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:59:28 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/21 10:35:13 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_keyboard(int key, t_game_instance *game_init)
{
	ft_non_special(key, game_init);
	if (key == W || key == UP)
	{
		game_init->game_objs.player = game_init->game_objs.player_up;
		ft_events_pressed(game_init, 0, -1);
	}
	else if (key == A || key == LEFT)
	{
		game_init->game_objs.player = game_init->game_objs.player_left;
		ft_events_pressed(game_init, -1, 0);
	}
	else if (key == S || key == DOWN)
	{
		game_init->game_objs.player = game_init->game_objs.player_down;
		ft_events_pressed(game_init, 0, +1);
	}
	else if (key == D || key == RIGHT)
	{
		game_init->game_objs.player = game_init->game_objs.player_right;
		ft_events_pressed(game_init, +1, 0);
	}
	return (0);
}

int	ft_non_special(int key, t_game_instance *game_init)
{
	if (key == ESC)
	{
		ft_printf("\nOh, is this game a little hard for you? :c\n");
		ft_exit_program(game_init);
	}
	return (0);
}

void	ft_win(t_game_instance *game_init)
{
	game_init->map_init.matrice[game_init->positions_init.player_row]
	[game_init->positions_init.player_col] = EMPTY;
	game_init->game_data.count_movements++;
	ft_printf("\nGreat! Maradona did it, he es free.\n");
	ft_exit_program(game_init);
}
