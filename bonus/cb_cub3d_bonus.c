/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_cub3d_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:49:07 by aiturria          #+#    #+#             */
/*   Updated: 2024/09/08 14:21:27 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cb_error(t_game *game, char *str)
{
	while (*str)
		write (2, str++, 1);
	cb_freeall(game);
	exit (EXIT_FAILURE);
}

void	cb_deltexture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 15)
		mlx_delete_texture(game->texture->shotgun[i++]);
	i = 0;
	while (i < 7)
		mlx_delete_texture(game->texture->opening[i++]);
	mlx_delete_texture(game->texture->north);
	mlx_delete_texture(game->texture->south);
	mlx_delete_texture(game->texture->east);
	mlx_delete_texture(game->texture->west);
	mlx_delete_texture(game->texture->door1);
}

void	cb_freeall(t_game *game)
{
	int	i;

	i = 0;
	cb_deltexture(game);
	while (game->map->map2d[i])
		free(game->map->map2d[i++]);
	free(game->map->map2d);
	free(game->map);
	free(game->pyr);
	free(game->ray);
	free(game->texture);
	mlx_delete_image(game->mlx42, game->img);
	mlx_close_window(game->mlx42);
	mlx_terminate(game->mlx42);
}

static void	cb_savemap(t_game *game, char *map)
{
	int		fd;
	int		i;

	i = 0;
	game->map->rows = 11;
	game->map->cols = 20;
	game->map->map2d = malloc(sizeof(char **) * (game->map->rows + 1));
	if (game->map->map2d == NULL)
		cb_error(game, "Error: memory allocation failure");
	fd = open(map, O_RDONLY);
	if (fd == -1)
		cb_error(game, "Error: file opening failure");
	while (i < game->map->rows)
	{
		game->map->map2d[i] = get_next_line(fd);
		if (game->map->map2d[i] == NULL)
			cb_error(game, "Error: file reading failure");
		i++;
	}
	game->map->map2d[i] = NULL;
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_memset(game, 0, sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	ft_memset(game->map, 0, sizeof(t_map));
	if (argc != 2)
		cb_error(game, "Error: wrong number of arguments");
	cb_savemap(game, argv[1]);
	cb_initgame(game);
	cb_freeall(game);
	exit(EXIT_SUCCESS);
}
