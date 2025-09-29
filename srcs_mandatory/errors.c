/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:59:10 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 00:01:26 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_init(int n)
{
	if (n == 1)
		ft_printf("Error\nPermission denied\n");
	else if (n == 2)
		ft_printf("Error\nNo exist map\n");
	else if (n == 3)
		ft_printf("Error\nCheck library compatibility!\n");
	exit(n);
}

void	ft_error_map(int n)
{
	if (n == 4)
		ft_printf("Error\nWrong number of arguments\n");
	else if (n == 5)
		ft_printf("Error\nThis is a directory.\n");
	else if (n == 6)
		ft_printf("Error\nBad extension\n");
	else if (n == 7)
		ft_printf("Error\nMemory allocation failed (malloc).\n");
	else if (n == 8)
		ft_printf("Error\nNo rectangular\n");
	else if (n == 9)
		ft_printf("Error\nNo player\n");
	else if (n == 10)
		ft_printf("Error\nNo exit\n");
	else if (n == 11)
		ft_printf("Error\nNo object\n");
	else if (n == 12)
		ft_printf("Error\nDuplicate player\n");
	else if (n == 13)
		ft_printf("Error\nDuplicate exit\n");
	else if (n == 14)
		ft_printf("Error\nNot surrounded by walls\n");
	else if (n == 15)
		ft_printf("Error\nWrong characters\n");
	else if (n == 16)
		ft_printf("Error\nNo valid path\n");
	else if (n == 17)
		ft_printf("Error\nTry create one valid map!\n");
	else
		ft_printf("Error\nUnknown error\n");
	exit(n);
}
