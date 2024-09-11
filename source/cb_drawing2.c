/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_drawing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:00:11 by aiturria          #+#    #+#             */
/*   Updated: 2024/09/10 17:02:45 by aiturria         ###   ########.fr       */
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

int	cb_revbytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}
