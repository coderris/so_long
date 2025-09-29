/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:59:48 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 12:00:16 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game_instance	game_init;
	int				result;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments\n");
		exit(4);
	}
	ft_struct_init(&game_init);
	result = ft_open_map(argv[1], &game_init);
	if (result > 0)
		ft_start_game(&game_init);
	else
		ft_handle_error(result, &game_init);
	ft_exit_program(&game_init);
	return (0);
}

void	ft_struct_init(t_game_instance *game_init)
{
	ft_memset(game_init, 0, sizeof(t_game_instance));
	game_init->map_init.matrice = NULL;
	game_init->mlx_ptr = NULL;
	game_init->win_ptr = NULL;
	game_init->resolutions_init.settings_name_map = NULL;
	game_init->resolutions_init.settings_name_window = NULL;
}

void	ft_start_game(t_game_instance *game_init)
{
	ft_initialize_game(game_init);
	ft_gameplay_start(game_init);
	mlx_loop(game_init->mlx_ptr);
}

void	ft_handle_error(int result, t_game_instance *game_init)
{
	ft_free_map(game_init);
	if (result == -2)
		ft_printf("Error\nNo exist map\n");
	else if (result == -3)
		ft_printf("Error\nBad extension\n");
	else if (result == -4)
		ft_printf("Error\nNo rectangular\n");
	else if (result == -10)
		ft_printf("Error\nNo player\n");
	else if (result == -11)
		ft_printf("Error\nNo exit\n");
	else if (result == -13)
		ft_printf("Error\nNo object\n");
	else if (result == -14)
		ft_printf("Error\nDuplicate player\n");
	else if (result == -15)
		ft_printf("Error\nDuplicate exit\n");
	else if (result == -16)
		ft_printf("Error\nNot surrounded by walls\n");
	else if (result == -17)
		ft_printf("Error\nWrong characters\n");
	else if (result == -18)
		ft_printf("Error\nNo valid path\n");
	else
		ft_printf("Error\nTry create one valid map!\n");
	exit(abs(result));
}
