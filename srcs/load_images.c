/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:03:31 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/05 00:42:17 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void load_images(t_game **game)
{
	int img_x;
	int img_y;
	int back_x;
	int back_y;
	t_images *images;
	 images = (t_images *)malloc(sizeof(t_images));
	images -> background_img =  mlx_xpm_file_to_image((*game) -> mlx_ptr, BACKGROUND_PATH, &back_x, &back_y); //segfault here
	images -> black_tile_img = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_PATH, &img_x, &img_y);
	images -> white_tile_img = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_PATH, &img_x, &img_y);
	(*game) -> images = images;


}

