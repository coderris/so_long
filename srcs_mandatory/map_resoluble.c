/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_resoluble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:28:35 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/21 20:28:35 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*ft_copy_row(char *src_row);
static void	ft_free_partial_copy(char **dst, int up_to);
static int	ft_test_path_validity(t_game_instance *game_init, char **mat_copy);
static char	**copy_map(char **src, int rows);
static void	free_map_copy(char **mat, int rows);
static int	find_player(t_player_search *search);
static void	flood_fill(t_flood_data *data, int x, int y);

static void	flood_fill(t_flood_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->rows || y >= data->cols)
		return ;
	if (data->mat[x][y] == '1' || data->mat[x][y] == 'V')
		return ;
	if (data->mat[x][y] == 'E')
	{
		*(data->exit_found) = 1;
		return ;
	}
	if (data->mat[x][y] == 'C')
		(*(data->collectibles))--;
	data->mat[x][y] = 'V';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}

static char	**copy_map(char **src, int rows)
{
	char	**dst;
	int		i;

	dst = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		dst[i] = ft_copy_row(src[i]);
		if (!dst[i])
		{
			ft_free_partial_copy(dst, i);
			return (NULL);
		}
		i++;
	}
	dst[rows] = NULL;
	return (dst);
}

static char	*ft_copy_row(char *src_row)
{
	int		row_len;
	int		j;
	char	*dst_row;

	row_len = 0;
	j = 0;
	while (src_row[j] && src_row[j] != '\n')
	{
		row_len++;
		j++;
	}
	dst_row = (char *)malloc((row_len + 1) * sizeof(char));
	if (!dst_row)
		return (NULL);
	j = 0;
	while (j < row_len)
	{
		dst_row[j] = src_row[j];
		j++;
	}
	dst_row[row_len] = '\0';
	return (dst_row);
}

static void	ft_free_partial_copy(char **dst, int up_to)
{
	while (--up_to >= 0)
		free(dst[up_to]);
	free(dst);
}

static void	free_map_copy(char **mat, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

static int	find_player(t_player_search *search)
{
	int	i;
	int	j;

	i = 0;
	while (i < search->rows)
	{
		j = 0;
		while (j < search->cols)
		{
			if (search->mat[i][j] == 'P')
			{
				*(search->x) = i;
				*(search->y) = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_map_resoluble(t_game_instance *game_init)
{
	char	**mat_copy;
	int		result;

	if (!game_init || !game_init->map_init.matrice)
		return (0);
	mat_copy = copy_map(game_init->map_init.matrice,
			game_init->map_init.rows_matrice);
	if (!mat_copy)
		return (0);
	result = ft_test_path_validity(game_init, mat_copy);
	free_map_copy(mat_copy, game_init->map_init.rows_matrice);
	return (result);
}

static int	ft_test_path_validity(t_game_instance *game_init, char **mat_copy)
{
	t_player_search	search;
	t_flood_data	flood_data;
	int				x;
	int				y;
	int				exit_found;
	int				collectibles;

	x = 0;
	y = 0;
	exit_found = 0;
	collectibles = game_init->game_data.count_collectible;
	
	search = (t_player_search){mat_copy, game_init->map_init.rows_matrice,
		game_init->map_init.cols_matrice, &x, &y};
	if (!find_player(&search))
		return (0);
	
	flood_data = (t_flood_data){mat_copy, game_init->map_init.rows_matrice,
		game_init->map_init.cols_matrice, &collectibles, &exit_found};
	flood_fill(&flood_data, x, y);
	
	return (collectibles == 0 && exit_found);
}
