/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:59:42 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 12:00:16 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_initialize_game(t_game_instance *game_init)
{
	game_init->mlx_ptr = mlx_init();
	if (game_init->mlx_ptr == NULL)
	{
		ft_printf("Error\nCheck library compatibility!\n");
		ft_free_map(game_init);
		exit(3);
	}
	game_init->game_data.count_movements = 0;
	ft_img_init(game_init);
	ft_locate_player(game_init);
	game_init->game_objs.player = game_init->game_objs.player_down;
	game_init->win_ptr = mlx_new_window(game_init->mlx_ptr,
			game_init->map_init.resolutions.settings_map_width
			* CELL_SIZE, game_init->map_init.resolutions.settings_map_height
			* CELL_SIZE, "Maradona and his passion");
	if (game_init->win_ptr == NULL)
	{
		ft_printf("Error\nCheck library compatibility!\n");
		ft_free_map(game_init);
		if (game_init->mlx_ptr)
		{
			mlx_destroy_display(game_init->mlx_ptr);
			free(game_init->mlx_ptr);
		}
		exit(3);
	}
}

void	ft_img_init(t_game_instance *game_init)
{
	ft_load_player_textures(game_init);
	ft_load_game_textures(game_init);
}

void	ft_load_player_textures(t_game_instance *game_init)
{
	ft_check_img(game_init, &game_init->game_objs.player_up,
		"rscs/textures/Player/walkUP_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_down,
		"rscs/textures/Player/walkDown_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_right,
		"rscs/textures/Player/walkRight_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_left,
		"rscs/textures/Player/walkLeft_00.xpm");
}

void	ft_load_game_textures(t_game_instance *game_init)
{
	ft_check_img(game_init, &game_init->game_objs.collectible,
		"rscs/textures/Collectibles/coin.xpm");
	ft_check_img(game_init, &game_init->game_objs.floor,
		"rscs/textures/Tiles/midBlocks_02.xpm");
	ft_check_img(game_init, &game_init->game_objs.exit_open,
		"rscs/textures/Exit/exit_open_01.xpm");
	ft_check_img(game_init, &game_init->game_objs.exit_close,
		"rscs/textures/Exit/exit_close_01.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall,
		"rscs/textures/Tiles/blockSimple.xpm");
}

void	ft_check_img(t_game_instance *game_init, void **image, char *path)
{
	int	width = 0;
	int	height = 0;

	*image = mlx_xpm_file_to_image(game_init->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{
		ft_printf("Error\nPermission denied or invalid texture file: %s\n", path);
		ft_exit_program(game_init);
	}
}
