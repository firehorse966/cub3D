/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:52:22 by aiturria          #+#    #+#             */
/*   Updated: 2024/09/08 11:17:59 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define SCREEN_W 2700
# define SCREEN_H  1800
# define SIZE 32
# define FOV 60
# define ROT_SPEED 0.045
# define PLAYER_SPEED 4
# define M_PI 3.14159265358979323846

# define BLACK 0x000000FF
# define GREY 0x808080FF
# define LIGHT_BLUE 0xADD8E6FF
# define BLUE 0x87CEEBFF
# define GREEN 0x008000FF
# define CYAN 0x00FFFFFF
# define MAGENTA 0xFF00FFFF
# define PURPLE 0x800080FF
# define PINK 0xFFC0CBFF
# define BROWN 0xA52A2AFF
# define YELLOW 0xFFFF00FF
# define ORANGE 0xFF9300FF
# define RED 0xFF0000FF
# define WHITE 0xFFFFFFFF

typedef struct s_player
{
	int		pyrx;
	int		pyry;
	double	angle;
	double	fovrad;
}	t_player;

typedef struct s_ray
{
	int		index;
	int		vertwall;
	double	angle;
	double	horizx;
	double	horizy;
	double	vertx;
	double	verty;
	double	distance;
}	t_ray;

typedef struct s_map
{
	char	**map2d;
	int		rows;
	int		cols;
	int		playerx;
	int		playery;
	int		width;
	int		height;
	int		*rgb;
}	t_map;

typedef struct s_game
{
	mlx_image_t		*img;
	mlx_t			*mlx42;
	t_map			*map;
	t_ray			*ray;
	t_player		*pyr;
}	t_game;

//general functions
void	cb_error(t_game *game, char *str);
void	cb_freeall(t_game *game);

//execution
void	cb_initgame(t_game *game);
void	cb_raycasting(t_game *game);
void	cb_drawing(t_game *game);
void	cb_keypress(mlx_key_data_t keydata, void *data);

#endif