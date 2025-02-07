/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:42:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/07 01:55:19 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void drawpieces(t_game **game);

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(game));
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 640, 640, "game");
	load_images(&game);
	start_pieces(&game);
	drawboard(&game);
	drawpieces(&game);
	mlx_hook((game) -> win_ptr, DestroyNotify, 0L, free_displays, &game);
	mlx_hook((game) -> win_ptr, 4, (1L<<2), mouse_input, &game );
	mlx_loop(game->mlx_ptr);
}
void	resetboard(t_game **game)
{
	drawboard(game);
	drawpieces(game);
}
void drawpieces(t_game **game)
{
	for (int column = 0; column < 8; column++)
	{
		for (int rowpos = 0; rowpos < 8; rowpos++)
		{
			if ((*game) -> tiles[column][rowpos] != -1)
			{
				if ((column  + rowpos) % 2 == 0)
					mlx_put_image_to_window((*game) -> mlx_ptr, (*game) -> win_ptr, (*game) -> images ->white_piece_img[(*game) -> tiles[column][rowpos]], (rowpos * 64) + 75, (column * 64) + 75);
				else
					mlx_put_image_to_window((*game) -> mlx_ptr, (*game) -> win_ptr, (*game) -> images ->piece_img[(*game) -> tiles[column][rowpos]], (rowpos * 64) + 75, (column * 64) + 75);
			}
		}
	}
}
