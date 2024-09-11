/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:52:22 by aiturria          #+#    #+#             */
/*   Updated: 2024/09/10 17:03:28 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define SCREEN_W 2700
# define SCREEN_H 1800
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
# define DARK_BROWN 0x4B2E1EFF
# define DARK_GREY 0x2F2F2FFF

typedef struct s_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	mlx_texture_t	*door1;
	mlx_texture_t	*shotgun[15];
	mlx_texture_t	*opening[7];
}	t_texture;

typedef struct s_player
{
	int		pyrx;
	int		pyry;
	double	angle;
	double	fovrad;
	int		mousex;
	int		mousey;
}	t_player;

typedef struct s_ray
{
	int		index;
	int		vertwall;
	int		doorx;
	int		doory;
	double	angle;
	double	horizx;
	double	horizy;
	double	vertx;
	double	verty;
	double	distance;
	double	height;
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
	int		rgb[2];
}	t_map;

typedef struct s_game
{
	mlx_image_t		*img;
	mlx_t			*mlx42;
	t_map			*map;
	t_ray			*ray;
	t_player		*pyr;
	t_texture		*texture;
	int				shoot;
	int				open;
	double			time;
}	t_game;

//general functions
void	cb_error(t_game *game, char *str);
void	cb_freeall(t_game *game);

//execution
void	cb_initgame(t_game *game);
void	cb_raycasting(t_game *game);
void	cb_drawing(t_game *game);
void	cb_keypress(mlx_key_data_t keydata, void *data);
int		cb_position(float angle, float *first, float *step, int check);
int		cb_revbytes(int c);
void	cb_rotate(t_game *game, int side);
void	cb_paintmap(t_game *game);
void	cb_paintboth(t_game *game, int top, int bottom);
void	cb_opendoor(t_game *game);
void	cb_closedoor(t_game *game, int x, int y);
void	cb_paintgun(t_game *game, mlx_texture_t *texture, int newx, int newy);
void	cb_loadopening(t_game *game);
void	cb_shooting(t_game *game);
void	cb_opening(t_game *game);

#endif