/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:42:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/06 21:28:04 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

t_game	*game;

void drawpieces(t_game **game);

void	client_signal_handler(int sig, siginfo_t *info, void *context)
{
	static int started;
	static int pos_i;
	static int				i;
	static int	c;
	t_game *game_ptr = game;
	// 0 - > from_col, 1 0 - > from_row, 2 -> to_col , 3 -> to_row //
	int pos[4];
	if (started == 0)
	{
		ft_printf("connected to server!\n");
		started = 1;
		return ;
	}
	if (sig == SIGUSR1)
	{
		ft_printf("receivec sigusr1\n");
		c |= 1 << i;
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("receivec sigusr2\n");
	}
	i++;
	if (i == 8)
		{
			pos[pos_i] = c;
			i = 0;
			c = 0;
			pos_i++;
			if (pos_i == 4)
			{
				ft_printf("col = %d, row = %d to_col %d, to _row %d\n",  pos[0], pos[1],pos[2], pos[3]);
				move(&game_ptr, pos[0], pos[1],pos[2], pos[3]);
				resetboard(&game_ptr);
				pos_i = 0;
				pos[0] = 0;
				pos [1] = 0;
				pos [2] = 0;
				pos [3] = 0;
			}
		}

}


int	main(int ac, char **av)
{

	struct sigaction	sigact;
	if (ac != 2)
	{
		ft_printf("use ./chess_client <pid>");
		return 0;
	}
	int pid = atoi(av[1]);
	sigact.sa_sigaction = &client_signal_handler;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	game = malloc(sizeof(t_game));
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 640, 640, "game");
	load_images(&game);
	start_pieces(&game);
	game -> server = false;
	game -> turn = 0;
	drawboard(&game);
	kill(pid, SIGUSR1);
	pause();
	game -> pid = pid;
	drawpieces(&game);
	mlx_hook((game) -> win_ptr, DestroyNotify, 0L, free_displays, &game);
	mlx_hook((game) -> win_ptr, 4, (1L<<2), mouse_input, &game);
	mlx_loop(game->mlx_ptr);
}
void	resetboard(t_game **game)
{
	drawboard(game);
	drawpieces(game);
}

void drawpieces(t_game **game)
{
	for (int column = 0; column < 8; column++)
	{
		for (int rowpos = 0; rowpos < 8; rowpos++)
		{
			if ((*game) -> tiles[7 - column][7 - rowpos] != -1)
			{
				if ((7 - column  + 7 - rowpos) % 2 == 0)
					mlx_put_image_to_window((*game) -> mlx_ptr, (*game) -> win_ptr, (*game) -> images ->white_piece_img[(*game) -> tiles[7 - column][ 7 - rowpos]], (rowpos * 64) + 75, (column * 64) + 75);
				else
					mlx_put_image_to_window((*game) -> mlx_ptr, (*game) -> win_ptr, (*game) -> images ->piece_img[(*game) -> tiles[7 - column][7 - rowpos]], (rowpos * 64) + 75, (column * 64) + 75);
			}
		}
	}
}
