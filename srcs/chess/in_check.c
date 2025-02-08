/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:49:56 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/08 21:01:43 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	in_check(t_game **game,int king_column, int king_row, int white)
{
	for (int from_column = 0; from_column < 8; from_column++)
	{
		for (int from_row = 0; from_row < 8; from_row++)
		{
			if ((white && (*game) -> tiles[from_column][from_row] != EMPTY && (*game) -> tiles[from_column][from_row] > 5) ||
				(!white && (*game) -> tiles[from_column][from_row] != EMPTY && (*game) -> tiles[from_column][from_row] < 6))
			{
				if (is_valid_move(game, from_column, from_row, king_column, king_row))
				{
					return (1);
				}
			}
		}
	}
	return (0);
}
