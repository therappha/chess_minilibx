/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:42:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/06 23:56:56 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int pid;
t_game	*game;
t_game *game_ptr;
void drawpieces(t_game **game);

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int started;
	static int pos_i;
	static int				i;
	static int	c;

	// 0 - > from_col, 1 0 - > from_row, 2 -> to_col , 3 -> to_row //
	int pos[4];
	if (!started)
	{
		pid = info -> si_pid;
		sleep(1);
		ft_printf("client connected!\n");
		kill(pid, SIGUSR1);
		started = 1;
		return ;
	}
	if (sig == SIGUSR1)
	{
		c |= 1 << i;
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
				if (is_valid_move(&game_ptr, pos[0], pos[1],pos[2], pos[3]))
				{
					move(&game_ptr, pos[0], pos[1],pos[2], pos[3]);
					resetboard(&game_ptr);
				}
				else
				{
					ft_printf("client tried to pass a invalid move!");
				}
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
	t_game	*game;
	struct sigaction	sigact;

	ft_printf("PID: [%d]\n", getpid());
	sigact.sa_sigaction = &signal_handler;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);

	game = malloc(sizeof(t_game));
	game->mlx_ptr = mlx_init();

	game->win_ptr = mlx_new_window(game->mlx_ptr, 640, 640, "game");
	game -> server = true;
	game -> turn = 0;
	load_images(&game);
	start_pieces(&game);
	drawboard(&game);
	pause();
	game_ptr = game;
	game -> pid = pid;
	drawpieces(&game);
	mlx_hook((game) -> win_ptr, DestroyNotify, 0L, free_displays, &game);
	mlx_hook((game) -> win_ptr, 4, (1L<<2), mouse_input, &game );
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
			if ((*game) -> tiles[column][rowpos] != -1)
			{
				if ((column  + rowpos) % 2 == 0)
					mlx_put_image_to_window((*game) -> mlx_ptr, (*game) -> win_ptr, (*game) -> images ->white_piece_img[(*game) -> tiles[column][rowpos]], (rowpos * 64) + 75, (column * 64) + 75);
				else
					mlx_put_image_to_window((*game) -> mlx_ptr, (*game) -> win_ptr, (*game) -> images ->piece_img[(*game) -> tiles[column][rowpos]], (rowpos * 64) + 75, (column * 64) + 75);
			}
		}
	}
}

