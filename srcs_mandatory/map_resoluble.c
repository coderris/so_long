/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_resoluble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:16:16 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/20 16:16:16 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
// Algoritmo flood fill para comprobar si el mapa es resoluble
static void flood_fill(char **mat, int rows, int cols,
                       int x, int y, int *collectibles, int *exit_found)
{
    if (x < 0 || y < 0 || x >= rows || y >= cols)
        return;
    if (mat[x][y] == '1' || mat[x][y] == 'V')
        return;
    if (mat[x][y] == 'E') {
        *exit_found = 1;     // La salida es alcanzable
        return;              // No atravesamos la E
    }
    if (mat[x][y] == 'C')
        (*collectibles)--;
    // Marca como visitado (incluye 'P' y '0' y ya marcados 'C')
    mat[x][y] = 'V';
    flood_fill(mat, rows, cols, x+1, y, collectibles, exit_found);
    flood_fill(mat, rows, cols, x-1, y, collectibles, exit_found);
    flood_fill(mat, rows, cols, x, y+1, collectibles, exit_found);
    flood_fill(mat, rows, cols, x, y-1, collectibles, exit_found);
}

// Copia la matriz de chars
static char **copy_map(char **src, int rows, int cols)
{
	int i, j;
	char **dst = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!dst) return NULL;
	for (i = 0; i < rows; i++) {
		dst[i] = (char *)malloc(sizeof(char) * (cols + 1));
		if (!dst[i]) {
			while (--i >= 0)
				free(dst[i]);
			free(dst);
			return NULL;
		}
		for (j = 0; j < cols; j++)
			dst[i][j] = src[i][j];
		dst[i][cols] = '\0';
	}
	dst[rows] = NULL;
	return dst;
}

// Libera la matriz de chars
static void free_map_copy(char **mat, int rows)
{
	int i;
	for (i = 0; i < rows; i++)
		free(mat[i]);
	free(mat);
}

static int find_player(char **mat, int rows, int cols, int *x, int *y)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] == 'P') { *x = i; *y = j; return 1; }
    return 0;
}

int ft_is_map_resoluble(t_game_instance *game_init)
{
    int x = 0, y = 0, exit_found = 0, collectibles = 0;

    if (!game_init || !game_init->map_init.matrice)
        return 0;

    for (int i = 0; i < game_init->map_init.rows_matrice; i++)
        for (int j = 0; j < game_init->map_init.cols_matrice; j++)
            if (game_init->map_init.matrice[i][j] == 'C')
                collectibles++;

    char **mat_copy = copy_map(game_init->map_init.matrice,
                               game_init->map_init.rows_matrice,
                               game_init->map_init.cols_matrice);
    if (!mat_copy)
        return 0;

    if (!find_player(mat_copy, game_init->map_init.rows_matrice,
                     game_init->map_init.cols_matrice, &x, &y)) {
        free_map_copy(mat_copy, game_init->map_init.rows_matrice);
        return 0;
    }

    flood_fill(mat_copy, game_init->map_init.rows_matrice,
               game_init->map_init.cols_matrice, x, y,
               &collectibles, &exit_found);

    free_map_copy(mat_copy, game_init->map_init.rows_matrice);

    // Válido si todos los C son alcanzables y la E es alcanzable
    return (collectibles == 0 && exit_found);
}
