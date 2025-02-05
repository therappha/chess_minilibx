/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:09:31 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/05 18:18:44 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void left_button(t_game **game, int x, int y);

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
	int column = (y - 64) / 64;
	int rowpos = (x - 64) / 64;
	if ((*game) -> tiles[column][rowpos] != -1)
		highlight(game, column, rowpos);

	ft_printf("column %d, row %d\n", column, rowpos);
}
