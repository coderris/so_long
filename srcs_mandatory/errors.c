/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:59:10 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/25 01:14:39 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_init(int n)
{
	if (n == 38)
		ft_printf("%sError\nCheck library compatibility! \n", "\033[0;31m");
	if (n == 1)
		ft_printf("%sError\n Operation not permitted! \n", "\033[0;31m");
	if (n == 2)
		ft_printf("%sError\nNo such file or directory! \n", "\033[0;31m");
	exit(n);
}

void	ft_error_map(int n)
{
	if (n == 12)
		ft_printf("%sError\n Memory allocation failed (malloc).\n",
			"\033[0;31m");
	else if (n == 21)
		ft_printf("%sError\n This is a directory. \n", "\033[0;31m");
	else if (n == 22 || n == 52 || n == 59 || n == 24 || n == 5)
		ft_printf("%sError\n Usage: ./so_long <filename>.ber \n", "\033[0;31m");
	else if (n == 61)
		ft_printf("%sError\n Try create one valid map! \n", "\033[0;31m");
	exit(n);
}
