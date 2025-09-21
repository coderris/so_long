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

static void flood_fill(char **mat, int rows, int cols,
                       int x, int y, int *collectibles, int *exit_found)
{
    if (x < 0 || y < 0 || x >= rows || y >= cols)
        return;
    if (mat[x][y] == '1' || mat[x][y] == 'V')
        return;
    if (mat[x][y] == 'E') {
        *exit_found = 1;
        return;
    }
    if (mat[x][y] == 'C')
        (*collectibles)--;
    mat[x][y] = 'V';
    flood_fill(mat, rows, cols, x+1, y, collectibles, exit_found);
    flood_fill(mat, rows, cols, x-1, y, collectibles, exit_found);
    flood_fill(mat, rows, cols, x, y+1, collectibles, exit_found);
    flood_fill(mat, rows, cols, x, y-1, collectibles, exit_found);
}

static char **copy_map(char **src, int rows, int cols)
{
    int i;
    int j;
    char **dst;
    
    dst = (char **)malloc(sizeof(char *) * (rows + 1));
    if (!dst)
        return NULL;
    i = 0;
    while (i < rows)
    {
        dst[i] = (char *)malloc(sizeof(char) * (cols + 1));
        if (!dst[i])
        {
            i--;
            while (i >= 0)
            {
                free(dst[i]);
                i--;
            }
            free(dst);
            return NULL;
        }
        j = 0;
        while (j < cols)
        {
            dst[i][j] = src[i][j];
            j++;
        }
        dst[i][cols] = '\0';
        i++;
    }
    dst[rows] = NULL;
    return dst;
}

static void free_map_copy(char **mat, int rows)
{
    int i;
    i = 0;
    while (i < rows)
    {
        free(mat[i]);
        i++;
    }
    free(mat);
}

static int find_player(char **mat, int rows, int cols, int *x, int *y)
{
    int i;
    int j;
    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            if (mat[i][j] == 'P')
            {
                *x = i;
                *y = j;
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

int ft_is_map_resoluble(t_game_instance *game_init)
{
    int x;
    int y;
    int exit_found;
    int collectibles;
    int i;
    int j;
    char **mat_copy;

    x = 0;
    y = 0;
    exit_found = 0;
    collectibles = 0;
    if (!game_init || !game_init->map_init.matrice)
        return 0;
    i = 0;
    while (i < game_init->map_init.rows_matrice)
    {
        j = 0;
        while (j < game_init->map_init.cols_matrice)
        {
            if (game_init->map_init.matrice[i][j] == 'C')
                collectibles++;
            j++;
        }
        i++;
    }
    mat_copy = copy_map(game_init->map_init.matrice,
                        game_init->map_init.rows_matrice,
                        game_init->map_init.cols_matrice);
    if (!mat_copy)
        return 0;
    if (!find_player(mat_copy, game_init->map_init.rows_matrice,
                     game_init->map_init.cols_matrice, &x, &y))
    {
        free_map_copy(mat_copy, game_init->map_init.rows_matrice);
        return 0;
    }
    flood_fill(mat_copy, game_init->map_init.rows_matrice,
               game_init->map_init.cols_matrice, x, y,
               &collectibles, &exit_found);
    free_map_copy(mat_copy, game_init->map_init.rows_matrice);
    return (collectibles == 0 && exit_found);
}
