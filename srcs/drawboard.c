/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawboard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:08:14 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/05 00:43:03 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void drawboard(t_game **game)
{
	int	column;
	int row_pos;

	mlx_put_image_to_window((*game) -> mlx_ptr, (*game) -> win_ptr, (*game) -> images ->background_img, 0, 0);
	column = 0;
	while (column < 8)
	{
		row_pos = 0;
		while (row_pos < 8)
		{
			if (column % 2 == 0 && row_pos % 2 == 0)
				mlx_put_image_to_window((*game) -> mlx_ptr, (*game) ->win_ptr, (*game) -> images -> white_tile_img, (row_pos * 64) + 64, (column * 64) + 64);
			else if (column % 2 == 0)
				mlx_put_image_to_window((*game) -> mlx_ptr, (*game) ->win_ptr, (*game) -> images -> black_tile_img, (row_pos * 64) + 64, (column * 64 )+ 64);
			else if (row_pos % 2 == 0)
				mlx_put_image_to_window((*game) -> mlx_ptr, (*game) ->win_ptr, (*game) -> images -> black_tile_img, (row_pos * 64) + 64, (column * 64 )+ 64);
			else
				mlx_put_image_to_window((*game) -> mlx_ptr, (*game) ->win_ptr, (*game) -> images -> white_tile_img, (row_pos * 64) + 64, (column * 64 )+ 64);
			row_pos++;
		}
		column++;
	}
}
