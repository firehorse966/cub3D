/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angcampo <angcampo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:13:51 by aiturria          #+#    #+#             */
/*   Updated: 2024/09/18 18:16:15 by angcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_newwindow(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (game->img != NULL)
		mlx_delete_image(game->mlx42, game->img);
	game->img = mlx_new_image(game->mlx42, SCREEN_W, SCREEN_H);
	cb_raycasting(game);
	mlx_image_to_window(game->mlx42, game->img, 0, 0);
}

/*
void	cb_loadtextures(t_game *game)
{
	game->texture->north = mlx_load_png("./images/metal352.png");
	if (game->texture->north == NULL)
		cb_error(game, "Error: loading MLX texture");
	game->texture->south = mlx_load_png("./images/metal354.png");
	if (game->texture->south == NULL)
		cb_error(game, "Error: loading MLX texture");
	game->texture->east = mlx_load_png("./images/metal353.png");
	if (game->texture->east == NULL)
		cb_error(game, "Error: loading MLX texture");
	game->texture->west = mlx_load_png("./images/metal351.png");
	if (game->texture->west == NULL)
		cb_error(game, "Error: loading MLX texture");
}
*/

void	cb_playerangle(t_game *game)
{
	char	c;

	c = game->map->map2d[game->map->playery][game->map->playerx];
	if (c == 'N')
		game->pyr->angle = M_PI / 2;
	if (c == 'S')
		game->pyr->angle = 3 * M_PI / 2;
	if (c == 'E')
		game->pyr->angle = 0;
	if (c == 'W')
		game->pyr->angle = M_PI;
	game->pyr->pyrx = (game->map->playerx * SIZE) + SIZE / 2;
	game->pyr->pyry = (game->map->playery * SIZE) + SIZE / 2;
	game->pyr->fovrad = (FOV * M_PI / 180);
}

void	cb_initgame(t_game *game)
{
	if (FOV > 179 || FOV < 1)
		cb_error(game, "Error: parameters outside allowed range");
	game->pyr = malloc(sizeof(t_player));
	game->ray = malloc(sizeof(t_ray));
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx42 = mlx_init(SCREEN_W, SCREEN_H, "cub 3D", true);
	if (!game->mlx42)
		cb_error(game, "Error: MLX42 window did not open");
	cb_playerangle(game);
	mlx_key_hook(game->mlx42, &cb_keypress, game);
	mlx_loop_hook(game->mlx42, &cb_newwindow, game);
	mlx_loop(game->mlx42);
}
