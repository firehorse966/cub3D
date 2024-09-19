/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_check_doors_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angcampo <angcampo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:11:48 by angcampo          #+#    #+#             */
/*   Updated: 2024/09/19 19:13:52 by angcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	cb_is_door_exit(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == 'D');
}

/*
@return 1 if not ok, 0 if ok
*/
static int	cb_check_door_surroundings(t_game *game, int i, int j)
{
	char	**matrix;

	matrix = game->map->map2d;
	if (matrix[i + 1][j] == '1' && matrix[i - 1][j] == '1'
		&& cb_is_door_exit(matrix[i][j - 1])
		&& cb_is_door_exit(matrix[i][j + 1]))
		return (0);
	if (matrix[i][j - 1] == '1' && matrix[i][j + 1] == '1'
		&& cb_is_door_exit(matrix[i - 1][j])
		&& cb_is_door_exit(matrix[i + 1][j]))
		return (0);
	return (1);
}

/*
@param game with map that has correct characters and is closed
@return 1 if doors are correct, 0 if not
*/
int	cb_check_doors(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map->rows)
	{
		j = -1;
		while (++j < ft_strlen(game->map->map2d[i]) - 1)
		{
			if (game->map->map2d[i][j] == 'D'
				&& cb_check_door_surroundings(game, i, j))
				return (0);
		}
	}
	return (1);
}
