/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:17:27 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/05 23:07:16 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void highlight(t_game **game, int column, int rowpos, int color)
{
	if (column > 7 || rowpos > 7)
		return ;
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			if (j < 4 || j > 59 || i < 4 || i > 59)
				mlx_pixel_put((*game) -> mlx_ptr, (*game) -> win_ptr, (rowpos * 64) + 64 + j, (column * 64) + 64 + i, color);
		}
	}
}
