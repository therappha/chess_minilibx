/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:08:01 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/06 03:33:56 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int is_valid_pawn(t_game **game, int from_col, int from_row, int to_col, int to_row, int white)
{
	int to_piece = (*game) -> tiles[to_col][to_row];
	if (from_col == to_col && to_row == from_row)
		return 0;
	else if (white)
	{
		if (to_col >= from_col)
			return (0);
		if (from_col - to_col > 2)
			return (0);
		if (to_col == from_col -1 && to_row == from_row && to_piece == EMPTY)
			return (1);
		if (from_col == 6 && to_col == from_col -2 && to_row == from_row && to_piece == EMPTY &&  (*game)->tiles[from_col - 1][from_row] == EMPTY)
			return (1);
		if (to_col == from_col -1 && (to_row == from_row -1 || to_row == from_row + 1) && to_piece != EMPTY && to_piece > 5)
			return (1);
		return (0);
	}
	else
	{
		if (to_col <= from_col)
			return (0);
		if (to_col - from_col > 2)
			return (0);
		if (to_col == from_col + 1 && to_row == from_row && to_piece == EMPTY)
			return (1);
		if ( from_col == 1 && to_col == from_col + 2 && to_row == from_row && to_piece == EMPTY &&  (*game)->tiles[from_col + 1][from_row] == EMPTY)
			return (1);
		if (to_col == from_col + 1 && (to_row == from_row -1 || to_row == from_row + 1) && to_piece < 6 && to_piece != EMPTY)
			return (1);
		return (0);
	}
}

int is_valid_rook(t_game **game, int from_col, int from_row, int to_col, int to_row, int white)
{
	int row_step = 1;
	int col_step = 1;
	int to_piece = (*game) -> tiles[to_col][to_row];

	if (from_col != to_col && from_row != to_row)
		return (0);
	if (to_row == from_row)
		row_step = 0;
	else if (to_row < from_row)
		row_step = -1;
	if (to_col == from_col)
		col_step = 0;
	else if (to_col < from_col)
		col_step = -1;

	int current_col = from_col + col_step;
	int current_row = from_row + row_step;

	while (current_col != to_col || current_row != to_row)
	{
		if ((*game) -> tiles[current_col][current_row] != -1)
			break;
		current_col += col_step;
		current_row += row_step;
	}
	if (current_col == to_col && current_row == to_row)
	{
		if (white && (to_piece > 5 || to_piece == EMPTY))
			return (1);
		else if(!white && (to_piece < 6 || to_piece == EMPTY))
			return (1);
	}
	return (0);
}
int is_valid_knight(t_game **game, int from_col, int from_row, int to_col, int to_row, int white)
{
	int to_piece = (*game) -> tiles[to_col][to_row];
	if (to_col == from_col -2 || to_col == from_col + 2)
	{
		if (to_row == from_row -1 || to_row == from_row + 1 )
		{
			if (white && (to_piece > 5 || to_piece == EMPTY))
				return (1);
			else if(!white && (to_piece < 6 || to_piece == EMPTY))
				return (1);
		}
	}
	if (to_col == from_col -1 || to_col == from_col + 1)
	{
		if (to_row == from_row -2 || to_row == from_row + 2 )
		{
			if (white && (to_piece > 5 || to_piece == EMPTY))
				return (1);
			else if(!white && (to_piece < 6 || to_piece == EMPTY))
				return (1);
		}
	}
	return (0);
}

int is_valid_bishop(t_game **game, int from_col, int from_row, int to_col, int to_row, int white)
{
	int i = 1;
	int j = 1;

	int to_piece = (*game) -> tiles[to_col][to_row];
	if (to_row == from_row || to_col == from_col)
		return (0);
	if ((abs(to_col - from_col)) != abs(to_row - from_row))
		return (0);
	if (to_row < from_row)
		i = -1;
	if (to_col < from_col)
		j = -1;

	int current_col = from_col + j;
	int current_row = from_row + i;

	while (current_col != to_col && current_row != to_row)
	{
		if ((*game) -> tiles[current_col][current_row] != -1)
			break;
		current_col += j;
		current_row += i;
	}
	if (current_col == to_col && current_row == to_row)
	{
		if (white && (to_piece > 5 || to_piece == EMPTY))
			return (1);
		else if(!white && (to_piece < 6 || to_piece == EMPTY))
			return (1);
	}
	return (0);

}
int is_valid_king(t_game **game, int from_col, int from_row, int to_col, int to_row, int white)
{
	int to_piece = (*game) -> tiles[to_col][to_row];

	if (from_row == to_row && from_col == to_col)
		return (0);
	if (abs(to_col - from_col) > 1 || abs(to_row - from_row) > 1)
		return (0);
	if (white && (to_piece > 5 || to_piece == EMPTY))
		return (1);
	else if(!white && (to_piece < 6 || to_piece == EMPTY))
		return (1);
	return (0);
}
int is_valid_queen(t_game **game, int from_col, int from_row, int to_col, int to_row, int white)
{
	if (is_valid_bishop(game, from_col, from_row, to_col, to_row, white))
		return (1);
	else if (is_valid_rook(game, from_col, from_row, to_col, to_row, white))
		return (1);
	return (0);
}
