/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:03:31 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/04 20:32:58 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void load_images(t_game **game)
{
	int img_x;
	int img_y;

	t_data background;
	background.img = mlx_new_image((*game) -> mlx_ptr, 640, 640);
	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length, &background.endian);

	for (int i = 0; i <= 640; i++)
	{
		for (int j = 0; j <= 640; j++)
		{
			pixel_put(&background, i, j, 0x16662d);
		}
	}

	(*game) ->black_tile_img = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_PATH, &img_x, &img_y);
	(*game) ->white_tile_img = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_PATH, &img_x, &img_y);
	(*game) ->background_img = background.img;
	//if (!(*game) -> background_img)
		//ft_printf("failed to load background");

}

