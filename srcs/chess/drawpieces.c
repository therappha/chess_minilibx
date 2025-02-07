/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawpieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:07:07 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/05 23:03:17 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void start_pieces(t_game **game)
{
	(*game)->tiles = malloc(8 * sizeof(int *));
	for (int i = 0; i < 8; i++)
	(*game)->tiles[i] = malloc(8 * sizeof(int));

	for (int column = 0; column < 8; column++)
	{
		for (int rowpos = 0; rowpos < 8; rowpos++)
		{
			(*game) -> tiles[column][rowpos] = -1;
		}
	}
	// Place black pieces
	(*game)->tiles[0][0] = BLACK_ROOK;
	(*game)->tiles[0][1] = BLACK_KNIGHT;
	(*game)->tiles[0][2] = BLACK_BISHOP;
	(*game)->tiles[0][3] = BLACK_QUEEN;
	(*game)->tiles[0][4] = BLACK_KING;
	(*game)->tiles[0][5] = BLACK_BISHOP;
	(*game)->tiles[0][6] = BLACK_KNIGHT;
	(*game)->tiles[0][7] = BLACK_ROOK;
	for (int i = 0; i < 8; i++)
		(*game)->tiles[1][i] = BLACK_PAWN;

	// Place white pieces
	(*game)->tiles[7][0] = WHITE_ROOK;
	(*game)->tiles[7][1] = WHITE_KNIGHT;
	(*game)->tiles[7][2] = WHITE_BISHOP;
	(*game)->tiles[7][3] = WHITE_QUEEN;
	(*game)->tiles[7][4] = WHITE_KING;
	(*game)->tiles[7][5] = WHITE_BISHOP;
	(*game)->tiles[7][6] = WHITE_KNIGHT;
	(*game)->tiles[7][7] = WHITE_ROOK;
	for (int i = 0; i < 8; i++)
		(*game)->tiles[6][i] = WHITE_PAWN;
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
