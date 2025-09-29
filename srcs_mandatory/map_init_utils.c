/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:59:55 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 12:00:16 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_map_dimensions(t_game_instance *game_init)
{
	game_init->map_init.cols_matrice = get_cols_count(&game_init->map_init);
	if (game_init->map_init.cols_matrice == 0)
		return (0);
	game_init->map_init.rows_matrice = 0;
	while (game_init->map_init.matrice[game_init->map_init.rows_matrice])
		game_init->map_init.rows_matrice++;
	if (game_init->map_init.rows_matrice == 0)
		return (0);
	game_init->map_init.size_matrice = game_init->map_init.rows_matrice
		* game_init->map_init.cols_matrice;
	game_init->map_init.resolutions.settings_map_width
		= game_init->map_init.cols_matrice;
	game_init->map_init.resolutions.settings_map_height
		= game_init->map_init.rows_matrice;
	return (1);
}

int	get_cols_count(t_map_data *map_init)
{
	char	*row;
	int		cols_count;

	if (!map_init || !map_init->matrice || !map_init->matrice[0])
		return (0);
	row = map_init->matrice[0];
	cols_count = 0;
	while (*row && *row != '\n')
	{
		cols_count++;
		row++;
	}
	return (cols_count);
}

int	ft_map_extension(char *map)
{
	char	*file_extension;
	char	*filename;

	if (!map)
		return (0);
	if (map[ft_strlen(map) - 1] == '/')
		return (0);
	filename = ft_strrchr(map, '/');
	if (filename)
		filename++;
	else
		filename = map;
	if (filename[0] == '.')
		return (0);
	file_extension = ft_strrchr(map, '.');
	if (!file_extension)
		return (0);
	return (ft_strcmp(file_extension, ".ber") == 0);
}
