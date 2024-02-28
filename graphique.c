/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphique.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:51:01 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/23 14:15:52 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(char **map, void *mlx, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '1')
				mlx_put_image_to_window(mlx, data->mlx_win,
					data->img_wall, i * data->width, j * data->height);
			i++;
		}
		j++;
	}
}

void	put_floor(char **map, void *mlx, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	data->mlx_win = mlx_new_window(mlx,
			data->width * ft_strlen(data->map[0], 0),
			data->height * len(data->map), "Hello world!");
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			mlx_put_image_to_window(mlx, data->mlx_win, data->img_floor,
				i * data->width, j * data->height);
			i++;
		}
		j++;
	}
}

void	put_door(char **map, void *mlx, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				mlx_put_image_to_window(mlx, data->mlx_win, data->img_door,
					i * data->width, j * data->height);
			i++;
		}
		j++;
	}
}

void	put_player(char **map, void *mlx, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				mlx_put_image_to_window(mlx, data->mlx_win, data->img_player,
					i * data->width, j * data->height);
			i++;
		}
		j++;
	}
}

void	put_collectible(char **map, void *mlx, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				mlx_put_image_to_window(mlx, data->mlx_win,
					data->img_collectible, i * data->width, j * data->height);
			i++;
		}
		j++;
	}
}
