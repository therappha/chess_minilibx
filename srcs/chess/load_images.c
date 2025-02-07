/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:03:31 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/07 02:37:18 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void load_images(t_game **game)
{
	int img_x;
	int img_y;
	int back_x;
	int back_y;
	int pieces_x;
	int pieces_y;
// 	#define WHITE_ROOK 0
// #define WHITE_KNIGHT 1
// #define WHITE_BISHOP 2
// #define WHITE_QUEEN 3
// #define WHITE_KING 4
// #define WHITE_PAWN 5
// #define BLACK_ROOK 6
// #define BLACK_KNIGHT 7
// #define BLACK_BISHOP 8
// #define BLACK_QUEEN 9
// #define BLACK_KING 10
// #define BLACK_PAWN 11
	t_images *images;
	images = (t_images *)malloc(sizeof(t_images));
	images -> background_img =  mlx_xpm_file_to_image((*game) -> mlx_ptr, BACKGROUND_PATH, &back_x, &back_y);
	images -> black_tile_img = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_PATH, &img_x, &img_y);
	images -> white_tile_img = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_PATH, &img_x, &img_y);
	images -> piece_img[WHITE_ROOK] = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_ROOK_PATH, &pieces_x, &pieces_y);
	images -> piece_img[WHITE_KNIGHT] = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_KNIGHT_PATH, &pieces_x, &pieces_y);
	images -> piece_img[WHITE_BISHOP] = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_BISHOP_PATH, &pieces_x, &pieces_y);
	images -> piece_img[WHITE_QUEEN] = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_QUEEN_PATH, &pieces_x, &pieces_y);
	images -> piece_img[WHITE_KING] = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_KING_PATH, &pieces_x, &pieces_y);
	images -> piece_img[WHITE_PAWN] = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_PAWN_PATH, &pieces_x, &pieces_y);
	images -> piece_img[BLACK_ROOK] = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_ROOK_PATH, &pieces_x, &pieces_y);
	images -> piece_img[BLACK_KNIGHT] = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_KNIGHT_PATH, &pieces_x, &pieces_y);
	images -> piece_img[BLACK_BISHOP] = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_BISHOP_PATH, &pieces_x, &pieces_y);
	images -> piece_img[BLACK_QUEEN] = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_QUEEN_PATH, &pieces_x, &pieces_y);
	images -> piece_img[BLACK_KING] = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_KING_PATH, &pieces_x, &pieces_y);
	images -> piece_img[BLACK_PAWN] = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_PAWN_PATH, &pieces_x, &pieces_y);
	images -> white_piece_img[WHITE_ROOK] = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_ROOK_WHITE_PATH, &pieces_x, &pieces_y);
	images -> white_piece_img[WHITE_KNIGHT] = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_KNIGHT_WHITE_PATH, &pieces_x, &pieces_y);
	images -> white_piece_img[WHITE_BISHOP] = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_BISHOP_WHITE_PATH, &pieces_x, &pieces_y);
	images -> white_piece_img[WHITE_QUEEN] = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_QUEEN_WHITE_PATH, &pieces_x, &pieces_y);
	images -> white_piece_img[WHITE_KING] = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_KING_WHITE_PATH, &pieces_x, &pieces_y);
	images -> white_piece_img[WHITE_PAWN] = mlx_xpm_file_to_image((*game) -> mlx_ptr, WHITE_PAWN_WHITE_PATH, &pieces_x, &pieces_y);
	images -> white_piece_img[BLACK_ROOK] = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_ROOK_WHITE_PATH, &pieces_x, &pieces_y);
	images -> white_piece_img[BLACK_KNIGHT] = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_KNIGHT_WHITE_PATH, &pieces_x, &pieces_y);
	images -> white_piece_img[BLACK_BISHOP] = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_BISHOP_WHITE_PATH, &pieces_x, &pieces_y);
	images -> white_piece_img[BLACK_QUEEN] = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_QUEEN_WHITE_PATH, &pieces_x, &pieces_y);
	images -> white_piece_img[BLACK_KING] = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_KING_WHITE_PATH, &pieces_x, &pieces_y);
	images -> white_piece_img[BLACK_PAWN] = mlx_xpm_file_to_image((*game) -> mlx_ptr, BLACK_PAWN_WHITE_PATH, &pieces_x, &pieces_y);

	(*game) -> images = images;


}

