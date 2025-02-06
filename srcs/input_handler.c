/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:09:31 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/06 02:19:19 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void left_button(t_game **game, int x, int y);
void	move(t_game **game, int from_column, int from_row, int to_column, int to_row);

void handle_selected(t_game **game, int *sel_column, int *sel_row, int column, int row);

int	key_input(int keysym, t_game **game)
{
	if (keysym == XK_Escape)
		free_displays(game);
	return (0);
}

int	mouse_input(int keysym, int x, int y, t_game **game)
{
	if (!(x >= 64 && x <= 576 && y >= 64 && y <= 576))
		return (0);
	if (keysym == 1)
		left_button(game, x, y);

}
void left_button(t_game **game, int x, int y)
{
	static int selected_rowpos;
	static int selected_column;
	int column = (y - 64) / 64;
	int rowpos = (x - 64) / 64;
	handle_selected(game, &selected_column, &selected_rowpos, column, rowpos);
	ft_printf("column %d, row %d\n", column, rowpos);
}
void handle_selected(t_game **game, int *sel_column, int *sel_row, int column, int row)
{
	static int highlighted;
	static int turn;
	if (highlighted == 0 && (*game) -> tiles[column][row] != -1 )
	{
		highlight(game, column, row, 0x18a15c);
		highlighted = 1;
		highlight_valid_moves(game, column, row);
		*sel_column = column;
		*sel_row = row;
	}
	else if (highlighted == 1)
	{
		if (column == *sel_column && row == *sel_row)
		{
			resetboard(game);
			*sel_column = -1 ;
			*sel_row = -1;
			highlighted = 0;
		}
		else if ((*game) -> tiles[column][row] > 5 && (*game) -> tiles[*sel_column][*sel_row] > 5 )
		{
			resetboard(game);
			highlight(game, column, row, 0x18a15c);
			highlight_valid_moves(game, column, row);
			*sel_column = column;
			*sel_row = row;
		}
		else if ((*game) -> tiles[column][row] != -1 && (*game) -> tiles[column][row] <= 5 && (*game) -> tiles[*sel_column][*sel_row] <= 5 )
		{
			resetboard(game);
			highlight(game, column, row, 0xc7e312);
			highlight_valid_moves(game, column, row);
			*sel_column = column;
			*sel_row = row;
		}
		else
		{
			move(game, *sel_column, *sel_row, column, row);
			resetboard(game);
			*sel_column = -1 ;
			*sel_row = -1;
			highlighted = 0;

		}
	}
ft_printf("selected column: %d, selected row %d\n", *sel_column, *sel_row);



}
void	move(t_game **game, int from_column, int from_row, int to_column, int to_row)
{
	int temp;
	temp = (*game) -> tiles[from_column][from_row];
	(*game) -> tiles[from_column][from_row] = -1;
	(*game) -> tiles[to_column][to_row] = temp;
	ft_printf("moving piece!\n");

}

void highlight_valid_moves(t_game **game, int from_column, int from_row)
{
	for (int to_column = 0; to_column < 8; to_column++)
	{
		for (int to_row = 0; to_row < 8; to_row++)
		{
			switch ((*game)->tiles[from_column][from_row])
			{
				case WHITE_PAWN:
					if (is_valid_pawn(game, from_column, from_row, to_column, to_row, 1))
						highlight(game, to_column, to_row, 0xc1c418);
					break;
				case BLACK_PAWN:
					if (is_valid_pawn(game, from_column, from_row, to_column, to_row, 0))
						highlight(game, to_column, to_row, 0xc1c418);
					break;
				case WHITE_ROOK:
					if (is_valid_rook(game, from_column, from_row, to_column, to_row, 1))
						highlight(game, to_column, to_row, 0xc1c418);
					break;
				case BLACK_ROOK:
					if (is_valid_rook(game, from_column, from_row, to_column, to_row, 0))
						highlight(game, to_column, to_row, 0xc1c418);
					break;
				case BLACK_KNIGHT:
					if (is_valid_knight(game, from_column, from_row, to_column, to_row, 0))
						highlight(game, to_column, to_row, 0xc1c418);
					break;
				case WHITE_KNIGHT:
					if (is_valid_knight(game, from_column, from_row, to_column, to_row, 1))
						highlight(game, to_column, to_row, 0xc1c418);
					break;
				case WHITE_BISHOP:
					if (is_valid_bishop(game, from_column, from_row, to_column, to_row, 1))
						highlight(game, to_column, to_row, 0xc1c418);
					break;
				case BLACK_BISHOP:
					if (is_valid_bishop(game, from_column, from_row, to_column, to_row, 0))
						highlight(game, to_column, to_row, 0xc1c418);
					break;

			}
		}
	}
}

