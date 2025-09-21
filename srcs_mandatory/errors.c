/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:59:10 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/21 10:34:39 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_init(int n)
{
	if (n == 38)
		ft_printf("%sError\nCheck library compatibility! \n", COLOR_RED);
	if (n == 1)
		ft_printf("%sError\n Operation not permitted! \n", COLOR_RED);
	if (n == 2)
		ft_printf("%sError\nNo such file or directory! \n", COLOR_RED);
	exit(n);
}

void	ft_error_map(int n)
{
	if (n == 12)
		ft_printf("%sError\n Memory allocation failed (malloc).\n", COLOR_RED);
	else if (n == 21)
		ft_printf("%sError\n This is a directory. \n", COLOR_RED);
	else if (n == 22 || n == 52 || n == 59 || n == 24 || n == 5)
		ft_printf("%sError\n Usage: ./so_long <filename>.ber \n", COLOR_RED);
	else if (n == 61)
		ft_printf("%sError\n Try create one valid map! \n", COLOR_RED);
	exit(n);
}
