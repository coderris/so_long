/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:59:16 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 11:33:49 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_exit_program(t_game_instance *game_init)
{
	ft_printf("Closing the window and program..\n");
	if (game_init->mlx_ptr && game_init->game_objs.player_up)
		ft_free_img(game_init);
	ft_free_map(game_init);
	ft_cleanup(game_init);
	if (game_init->win_ptr && game_init->mlx_ptr)
		mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	if (game_init->mlx_ptr)
	{
		mlx_destroy_display(game_init->mlx_ptr);
		free(game_init->mlx_ptr);
	}
	exit(0);
	return (0);
}

void	ft_cleanup(t_game_instance *game_init)
{
	if (game_init->resolutions_init.settings_name_window != NULL)
	{
		free(game_init->resolutions_init.settings_name_window);
		game_init->resolutions_init.settings_name_window = NULL;
	}
	if (game_init->resolutions_init.settings_name_map != NULL)
	{
		free(game_init->resolutions_init.settings_name_map);
		game_init->resolutions_init.settings_name_map = NULL;
	}
}
