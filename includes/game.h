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

#ifndef game_H
# define game_H
# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/mlx/mlx_int.h"
# include <strings.h>
# include <limits.h>
# include <math.h>

//define values for pieces
#define WHITE_ROOK 1
#define WHITE_KNIGHT 2
#define WHITE_BISHOP 3
#define WHITE_QUEEN 4
#define WHITE_KING 5
#define WHITE_PAWN 6
#define BLACK_ROOK 7
#define BLACK_KNIGHT 8
#define BLACK_BISHOP 9
#define BLACK_QUEEN 10
#define BLACK_KING 11
#define BLACK_PAWN 12

//define image paths
#define WHITE_PATH "assets/board/white_tile.xpm"
#define BLACK_PATH "assets/board/black_tile.xpm"
#define BACKGROUND_PATH "assets/board/background.xpm"

typedef struct s_tile
{
	int	piece;

} t_tile;

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
	void *black_tile_img;
	void *white_tile_img;
	void *background_img;
	void *piece_img[11];
	t_tile tiles[7][7];
}	t_game;

int		free_displays(t_game **game);
void	drawboard(t_game **game);
void		load_images(t_game **game);
void	pixel_put(t_data *data, int x, int y, int color);


# endif
