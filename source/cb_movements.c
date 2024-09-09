/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:05:13 by aiturria          #+#    #+#             */
/*   Updated: 2024/09/09 12:08:06 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_movecheck(t_game *game, int posx, int posy)
{
	int	newx;
	int	newy;
	int	mapx;
	int	mapy;

	newx = roundf(game->pyr->pyrx + posx);
	newy = roundf(game->pyr->pyry + posy);
	mapx = newx / SIZE;
	mapy = newy / SIZE;
	if (game->map->map2d[mapy][mapx] != '1')
	{
		game->pyr->pyrx = newx;
		game->pyr->pyry = newy;
	}
}

void	cb_movements(t_game *game, int move)
{
	float	posx;
	float	posy;

	if (move == 1)
	{
		posx = cos(game->pyr->angle - M_PI / 2) * PLAYER_SPEED;
		posy = -sin(game->pyr->angle - M_PI / 2) * PLAYER_SPEED;
	}
	else if (move == 2)
	{
		posx = cos(game->pyr->angle + M_PI / 2) * PLAYER_SPEED;
		posy = -sin(game->pyr->angle + M_PI / 2) * PLAYER_SPEED;
	}
	else if (move == 3)
	{
		posx = cos(game->pyr->angle) * PLAYER_SPEED;
		posy = -sin(game->pyr->angle) * PLAYER_SPEED;
	}
	else
	{
		posx = -cos(game->pyr->angle) * PLAYER_SPEED;
		posy = sin(game->pyr->angle) * PLAYER_SPEED;
	}
	cb_movecheck(game, posx, posy);
}

/*void	cb_movements(t_game *game, int move)
{
	float posx;
	float posy;

	if (move == 1)
	{
		posx = sin(game->pyr->angle) * PLAYER_SPEED;
		posy = -cos(game->pyr->angle) * PLAYER_SPEED;
	}
	if (move == 2)
	{
		posx = -sin(game->pyr->angle) * PLAYER_SPEED;
		posy = cos(game->pyr->angle) * PLAYER_SPEED;
	}
	if (move == 3)
	{
		posx = -cos(game->pyr->angle) * PLAYER_SPEED;
		posy = -sin(game->pyr->angle) * PLAYER_SPEED;
	}
	if (move == 4)
	{
		posx = cos(game->pyr->angle) * PLAYER_SPEED;
		posy = sin(game->pyr->angle) * PLAYER_SPEED;
	}
	if ((game->pyr->angle > M_PI * 0.60 && game->pyr->angle < M_PI * 1.40)
		|| (game->pyr->angle < M_PI * 0.40 || game->pyr->angle > M_PI * 1.60))
	{
		posx *= -1;
		posy *= -1;
	}
	cb_movecheck(game, posx, posy);
}*/

void	cb_rotate(t_game *game, int side)
{
	if (side == 2)
	{
		game->pyr->angle += ROT_SPEED;
		if (game->pyr->angle > 2 * M_PI)
			game->pyr->angle -= 2 * M_PI;
	}
	else
	{
		game->pyr->angle -= ROT_SPEED;
		if (game->pyr->angle < 0)
			game->pyr->angle += 2 * M_PI;
	}
}

void	cb_keypress(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		cb_error(game, "exit");
	else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		cb_rotate(game, 1);
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		cb_rotate(game, 2);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		cb_movements(game, 1);
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		cb_movements(game, 2);
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		cb_movements(game, 3);
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		cb_movements(game, 4);
}
