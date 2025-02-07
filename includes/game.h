/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:13 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/28 23:23:25 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/mlx/mlx_int.h"
# include <strings.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <signal.h>

//define values for pieces
#define WHITE_ROOK 0
#define WHITE_KNIGHT 1
#define WHITE_BISHOP 2
#define WHITE_QUEEN 3
#define WHITE_KING 4
#define WHITE_PAWN 5
#define BLACK_ROOK 6
#define BLACK_KNIGHT 7
#define BLACK_BISHOP 8
#define BLACK_QUEEN 9
#define BLACK_KING 10
#define BLACK_PAWN 11
#define EMPTY -1
//define image paths
#define WHITE_PATH "assets/board/white_tile.xpm"
#define BLACK_PATH "assets/board/black_tile.xpm"
#define BACKGROUND_PATH "assets/board/background.xpm"

// Define piece image paths
#define WHITE_ROOK_PATH "assets/pieces/white_rook.xpm"
#define WHITE_KNIGHT_PATH "assets/pieces/white_knight.xpm"
#define WHITE_BISHOP_PATH "assets/pieces/white_bishop.xpm"
#define WHITE_QUEEN_PATH "assets/pieces/white_queen.xpm"
#define WHITE_KING_PATH "assets/pieces/white_king.xpm"
#define WHITE_PAWN_PATH "assets/pieces/white_pawn.xpm"

#define BLACK_ROOK_PATH "assets/pieces/black_rook.xpm"
#define BLACK_KNIGHT_PATH "assets/pieces/black_knight.xpm"
#define BLACK_BISHOP_PATH "assets/pieces/black_bishop.xpm"
#define BLACK_QUEEN_PATH "assets/pieces/black_queen.xpm"
#define BLACK_KING_PATH "assets/pieces/black_king.xpm"
#define BLACK_PAWN_PATH "assets/pieces/black_pawn.xpm"

#define WHITE_ROOK_WHITE_PATH "assets/pieces/white_rook_white.xpm"
#define WHITE_KNIGHT_WHITE_PATH "assets/pieces/white_knight_white.xpm"
#define WHITE_BISHOP_WHITE_PATH "assets/pieces/white_bishop_white.xpm"
#define WHITE_QUEEN_WHITE_PATH "assets/pieces/white_queen_white.xpm"
#define WHITE_KING_WHITE_PATH "assets/pieces/white_king_white.xpm"
#define WHITE_PAWN_WHITE_PATH "assets/pieces/white_pawn_white.xpm"

#define BLACK_ROOK_WHITE_PATH "assets/pieces/black_rook_white.xpm"
#define BLACK_KNIGHT_WHITE_PATH "assets/pieces/black_knight_white.xpm"
#define BLACK_BISHOP_WHITE_PATH "assets/pieces/black_bishop_white.xpm"
#define BLACK_QUEEN_WHITE_PATH "assets/pieces/black_queen_white.xpm"
#define BLACK_KING_WHITE_PATH "assets/pieces/black_king_white.xpm"
#define BLACK_PAWN_WHITE_PATH "assets/pieces/black_pawn_white.xpm"

typedef struct s_images
{
	void *black_tile_img;
	void *white_tile_img;
	void *background_img;
	void *piece_img[12];
	void *white_piece_img[12];
} t_images;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef	struct	s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_images*images;
	int		**tiles;
	bool	server;
	int		turn;
	int		pid;
}	t_game;

int		free_displays(t_game **game);
void	drawboard(t_game **game);
void	load_images(t_game **game);
void	pixel_put(t_data *data, int x, int y, int color);
void	start_pieces(t_game **game);
int	mouse_input(int keysym, int x, int y, t_game **game);
void highlight(t_game **game, int column, int rowpos, int color);
void	resetboard(t_game **game);
void	emit_sig(int pid, char c);

int redraw_window(t_game **game);


//valid moves
int is_valid_pawn(t_game **game, int from_col, int from_row, int to_col, int to_row, int white);
int is_valid_rook(t_game **game, int from_col, int from_row, int to_col, int to_row, int white);
int is_valid_knight(t_game **game, int from_col, int from_row, int to_col, int to_row, int white);
int is_valid_bishop(t_game **game, int from_col, int from_row, int to_col, int to_row, int white);
int is_valid_king(t_game **game, int from_col, int from_row, int to_col, int to_row, int white);
int is_valid_queen(t_game **game, int from_col, int from_row, int to_col, int to_row, int white);
int is_valid_move(t_game **game, int from_column, int from_row, int to_column, int to_row);
void highlight_valid_moves(t_game **game, int from_column, int from_row);
void	move(t_game **game, int from_column, int from_row, int to_column, int to_row);


# endif
