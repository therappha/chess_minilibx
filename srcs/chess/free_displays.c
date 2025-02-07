/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_displays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:41:42 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/07 01:19:17 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	free_displays(t_game **game)
{
	mlx_destroy_window((*game) -> mlx_ptr, (*game) -> win_ptr);
	mlx_destroy_display((*game) -> mlx_ptr);
	ft_printf("Closing Application!");
	exit(1);
	return (0);
}

