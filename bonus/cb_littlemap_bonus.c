/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_littlemap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:30:23 by aiturria          #+#    #+#             */
/*   Updated: 2024/09/08 13:04:25 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cb_paintsquare(t_game *game, int x, int y, int color)
{
	int		newx;
	int		newy;
	double	start;

	start = 0.70;
	newy = (SCREEN_H * start) + y;
	while (newy < (SCREEN_H * start) + y + SIZE)
	{
		newx = (SCREEN_W * start) + (SCREEN_W / 4) - (x + SIZE);
		while (newx < (SCREEN_W * start) + (SCREEN_W / 4) - x)
			mlx_put_pixel(game->img, newx++, newy, color);
		newy++;
	}
}

void	cb_paintplayer(t_game *game)
{
	int	x;
	int	y;
	int	rad;
	int	pyrx;
	int	pyry;

	pyrx = (SCREEN_W * 0.70) + (SCREEN_W / 4) - (game->pyr->pyrx);
	pyry = (SCREEN_H * 0.70) + game->pyr->pyry;
	rad = SIZE / 6;
	y = -rad;
	while (y <= rad)
	{
		x = -rad;
		while (x <= rad)
		{
			if (pow(x, 2) + pow(y, 2) <= pow(rad, 2))
				mlx_put_pixel(game->img, pyrx + x, pyry + y, YELLOW);
			x++;
		}
		y++;
	}
}

void	cb_paintlooking(t_game *game)
{
	double	angle;
	double	beginx;
	double	beginy;
	double	i;

	i = 0;
	angle = game->pyr->angle + M_PI + ((M_PI / 180) * 30);
	while (angle >= game->pyr->angle + M_PI - ((M_PI / 180) * 30))
	{
		beginx = SCREEN_W * 0.70 + (SCREEN_W / 4) - (game->pyr->pyrx);
		beginy = (SCREEN_H * 0.70) + game->pyr->pyry;
		i = 0;
		while (i < 110)
		{
			beginx += cos(angle);
			beginy += sin(angle);
			mlx_put_pixel(game->img, beginx, beginy, CYAN);
			i++;
		}
		angle = angle - 0.10;
	}
}

void	cb_paintmap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map2d[y])
	{
		x = 0;
		while (game->map->map2d[y][x] && game->map->map2d[y][x] != '\n')
		{
			if (game->map->map2d[y][x] == '1')
				cb_paintsquare(game, x * SIZE, y * SIZE, BLACK);
			else if (game->map->map2d[y][x] == 'D')
				cb_paintsquare(game, x * SIZE, y * SIZE, LIGHT_BLUE);
			else
				cb_paintsquare(game, x * SIZE, y * SIZE, GREY);
			x++;
		}
		y++;
	}
	cb_paintplayer(game);
	cb_paintlooking(game);
}
