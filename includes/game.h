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

typedef struct s_tile
{
	int	piece;

} t_tile;
typedef struct s_images
{
	void *black_tile_img;
	void *white_tile_img;
	void *background_img;
	void *piece_img[12];
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
	t_images *images;
	t_tile tiles[8][8];
}	t_game;

int		free_displays(t_game **game);
void	drawboard(t_game **game);
void		load_images(t_game **game);
void	pixel_put(t_data *data, int x, int y, int color);


# endif
