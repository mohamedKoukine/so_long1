/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:37:52 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/27 17:13:55 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free (map);
}

int	open_the_door(t_data *data, int k)
{
	int	i;
	int	j;
	int	l;

	j = 0;
	l = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'C')
				l++;
			i++;
		}
		j++;
	}
	if (l == 0 && k == 1)
	{
		data = get_player_bonus(data->map, data, 0, 'E');
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_door_open,
			data->yp * data->width, data->xp * data->height);
	}
	return (l);
}

static int	ft_move(int keycode, void *p)
{
	if (keycode == 126)
		ft_move_up_bonus(p);
	else if (keycode == 125)
		ft_move_down_bonus(p);
	else if (keycode == 124)
		ft_move_right_bonus(p);
	else if (keycode == 123)
		ft_move_left_bonus(p);
	else if (keycode == 53)
		exit (1);
	open_the_door(p, 1);
	return (0);
}

static void	fill_img(t_data *data, void *mlx)
{
	data->count = 0;
	data->img_wall = mlx_xpm_file_to_image(mlx,
			"wall.xpm", &data->width, &data->height);
	data->img_player = mlx_xpm_file_to_image(mlx,
			"face.xpm", &data->width, &data->height);
	data->img_left = mlx_xpm_file_to_image(mlx,
			"left.xpm", &data->width, &data->height);
	data->img_right = mlx_xpm_file_to_image(mlx,
			"right.xpm", &data->width, &data->height);
	data->img_back = mlx_xpm_file_to_image(mlx,
			"back.xpm", &data->width, &data->height);
	data->img_door = mlx_xpm_file_to_image(mlx,
			"bab.xpm", &data->width, &data->height);
	data->img_door_open = mlx_xpm_file_to_image(mlx,
			"bab_open.xpm", &data->width, &data->height);
	data->img_floor = mlx_xpm_file_to_image(mlx,
			"floor.xpm", &data->width, &data->height);
	data->img_collectible = mlx_xpm_file_to_image(mlx,
			"ping.xpm", &data->width, &data->height);
	data->img_trap = mlx_xpm_file_to_image(mlx,
			"trap.xpm", &data->width, &data->height);
}

int	main(int ac, char **av)
{
	int		i;
	t_data	data;

	if (ac == 2)
	{
		i = ft_strlen(av[1], 0);
		if (i <= 4 || av[1][i - 1] != 'r' || av[1][i - 2] != 'e'
			|| av[1][i - 3] != 'b' || av[1][i - 4] != '.')
			ft_error("name_file");
		data.map = parsing_bonus (av[1], &data, NULL);
		data.mlx = mlx_init();
		fill_img(&data, data.mlx);
		put_floor(data.map, data.mlx, &data);
		put_wall(data.map, data.mlx, &data);
		put_door(data.map, data.mlx, &data);
		put_door(data.map, data.mlx, &data);
		put_collectible(data.map, data.mlx, &data);
		put_player(data.map, data.mlx, &data);
		mlx_hook(data.mlx_win, 2, 0, ft_move, &data);
		mlx_loop(data.mlx);
		free_all (data.map);
	}
}