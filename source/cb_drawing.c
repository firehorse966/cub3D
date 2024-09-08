/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:15:59 by aiturria          #+#    #+#             */
/*   Updated: 2024/09/08 11:16:23 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_paintboth(t_game *game, int top, int bottom)
{
	int	i;

	i = 0;
	while (i < top)
		mlx_put_pixel(game->img, game->ray->index, i++, CYAN);
	i = bottom;
	while (i < SCREEN_H)
		mlx_put_pixel(game->img, game->ray->index, i++, GREEN);
}

int	findcolor(t_game *game)
{
	if (game->ray->vertwall == 1)
	{
		if (game->ray->angle > M_PI / 2 && game->ray->angle < 1.5 * M_PI)
			return (ORANGE);
		else
			return (YELLOW);
	}
	else
	{
		if (game->ray->angle > M_PI)
			return (RED);
		else
			return (MAGENTA);
	}
}

void	cb_paintwall(t_game *game, int top, int bottom)
{
	int	color;

	color = findcolor(game);
	while (top < bottom)
		mlx_put_pixel(game->img, game->ray->index, top++, color);
}

void	cb_drawing(t_game *game)
{
	double	height;
	double	top;
	double	bottom;

	game->ray->distance = cos(game->ray->angle - game->pyr->angle)
		* game->ray->distance;
	height = (SIZE / game->ray->distance) * ((SCREEN_W / 2)
			/ tan(game->pyr->fovrad / 2));
	top = (SCREEN_H / 2) - (height / 2);
	if (top < 0)
		top = 0;
	bottom = (SCREEN_H / 2) + (height / 2);
	if (bottom > SCREEN_H)
		bottom = SCREEN_H;
	cb_paintwall(game, top, bottom);
	cb_paintboth(game, top, bottom);
}
