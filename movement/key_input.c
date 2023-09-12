#include "../include/cub3d.h"

int	key_press_handler(int key, t_game *game)
{
	if (key == MAC_KEY_ESCAPE)
		free_exit(game, 0);
	if (key == MAC_KEY_LEFT)
		game->player.rotate -= 1;
	if (key == MAC_KEY_RIGHT)
		game->player.rotate += 1;
	if (key == MAC_KEY_W)
		game->player.move_y = 1;
	if (key == MAC_KEY_A)
		game->player.move_x = -1;
	if (key == MAC_KEY_S)
		game->player.move_y = -1;
	if (key == MAC_KEY_D)
		game->player.move_x = 1;
	if (key == MAC_KEY_SHIFT_LEFT)
		game->player.speed = 0.7;
	return (0);
}

int	key_release_handler(int key, t_game *game)
{
	if (key == MAC_KEY_ESCAPE)
		free_exit(game, 0);
	if (key == MAC_KEY_W && game->player.move_y == 1)
		game->player.move_y = 0;
	if (key == MAC_KEY_S && game->player.move_y == -1)
		game->player.move_y = 0;
	if (key == MAC_KEY_A && game->player.move_x == -1)
		game->player.move_x += 1;
	if (key == MAC_KEY_D && game->player.move_x == 1)
		game->player.move_x -= 1;
	if (key == MAC_KEY_LEFT && game->player.rotate <= 1)
		game->player.rotate = 0;
	if (key == MAC_KEY_RIGHT && game->player.rotate >= -1)
		game->player.rotate = 0;
	if (key == MAC_KEY_SHIFT_LEFT)
		game->player.speed = SPEED;
	return (0);
}

void	key_input(t_game *game)
{
	mlx_hook(game->win, 17, 1L << 17, end_game, game);
	mlx_hook(game->win, 02, (1L<<0), key_press_handler, game);
	mlx_hook(game->win, 03, (1L<<1), key_release_handler, game);
}

// void	key_input(t_game *game)
// {
// 	mlx_hook(game->win, mlx_key_hook, MAC_KEY_ESCAPE, end_game, game);
// 	// mlx_hook(game->win, 17, 1L << 17, end_game, game);
// 	mlx_key_hook(game->win, key_press_handler, game);
// 	mlx_hook(game->win, 03, (1L<<1), key_release_handler, game);
// }