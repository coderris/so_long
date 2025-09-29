/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:59:21 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 11:33:49 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_map(t_game_instance *game_init)
{
	int	i;

	if (game_init->map_init.matrice == NULL)
		return ;
	i = 0;
	while (game_init->map_init.matrice[i])
	{
		free(game_init->map_init.matrice[i]);
		i++;
	}
	free(game_init->map_init.matrice);
	game_init->map_init.matrice = NULL;
	return ;
}

void	ft_free_img(t_game_instance *game_init)
{
	if (!game_init->mlx_ptr)
		return ;
	ft_free_player_textures(game_init);
	ft_free_game_textures(game_init);
	game_init->game_objs = (t_game_objs){0};
}

void	ft_free_player_textures(t_game_instance *game_init)
{
	if (game_init->game_objs.player_up)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_up);
	if (game_init->game_objs.player_left)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_left);
	if (game_init->game_objs.player_right)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_right);
	if (game_init->game_objs.player_down)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_down);
}

void	ft_free_game_textures(t_game_instance *game_init)
{
	if (game_init->game_objs.collectible)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.collectible);
	if (game_init->game_objs.exit_open)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.exit_open);
	if (game_init->game_objs.exit_close)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.exit_close);
	if (game_init->game_objs.wall)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall);
	if (game_init->game_objs.floor)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.floor);
}
