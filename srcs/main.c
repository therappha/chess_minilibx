/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:42:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/04 19:41:19 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"


int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(game));
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 640, 640, "game");
	load_images(&game);
	drawboard(&game);
	mlx_hook((game) -> win_ptr, DestroyNotify, 0L, free_displays, &game);
	mlx_loop(game->mlx_ptr);
}
