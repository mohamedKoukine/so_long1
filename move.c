/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:56:15 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/23 14:45:41 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_swap(t_data *data, int x, int y, char c)
{
	if (c == 'u')
	{
		data->map[x][y] = '0';
		data->map[x - 1][y] = 'P';
	}
	else if (c == 'd')
	{
		data->map[x][y] = '0';
		data->map[x + 1][y] = 'P';
	}
	else if (c == 'r')
	{
		data->map[x][y] = '0';
		data->map[x][y + 1] = 'P';
	}
	else if (c == 'l')
	{
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'P';
	}
}

void	ft_move_up(t_data *data)
{
	data = get_player((data)->map, data, 0, 'P');
	if (data->map[data->xp - 1][data->yp] == '0' ||
		data->map[data->xp - 1][data->yp] == 'C')
	{
		ft_putnbr(++data->count);
		write (1, "\n", 1);
		ft_swap(data, data->xp, data->yp, 'u');
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			data->yp * data->width, data->xp * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			data->yp * data->width, (data->xp - 1) * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_back,
			data->yp * data->width, (data->xp - 1) * data->height);
	}
	else if (data->map[data->xp - 1][data->yp] == 'E'
		&& !open_the_door(data, 0))
	{
		ft_putnbr(++data->count);
		write (1, "\n", 1);
		exit (0);
	}
}

void	ft_move_down(t_data *data)
{
	data = get_player((data)->map, data, 0, 'P');
	if (data->map[data->xp + 1][data->yp] == '0' ||
		data->map[data->xp + 1][data->yp] == 'C')
	{
		ft_putnbr(++data->count);
		write (1, "\n", 1);
		ft_swap(data, data->xp, data->yp, 'd');
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			data->yp * data->width, data->xp * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			data->yp * data->width, (data->xp + 1) * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_player,
			data->yp * data->width, (data->xp + 1) * data->height);
	}
	else if (data->map[data->xp + 1][data->yp] == 'E'
		&& !open_the_door(data, 0))
	{
		ft_putnbr(++data->count);
		write (1, "\n", 1);
		exit (0);
	}
}

void	ft_move_right(t_data *data)
{
	data = get_player((data)->map, data, 0, 'P');
	if (data->map[data->xp][data->yp + 1] == '0' ||
	data->map[data->xp][data->yp + 1] == 'C')
	{
		ft_putnbr(++data->count);
		write (1, "\n", 1);
		ft_swap(data, data->xp, data->yp, 'r');
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			data->yp * data->width, data->xp * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			(data->yp + 1) * data->width, data->xp * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_right,
			(data->yp + 1) * data->width, data->xp * data->height);
	}
	else if (data->map[data->xp][data->yp + 1] == 'E'
		&& !open_the_door(data, 0))
	{
		ft_putnbr(++data->count);
		write (1, "\n", 1);
		exit (0);
	}
}

void	ft_move_left(t_data *data)
{
	data = get_player((data)->map, data, 0, 'P');
	if (data->map[data->xp][data->yp - 1] == '0' ||
		data->map[data->xp][data->yp - 1] == 'C')
	{
		ft_putnbr(++data->count);
		write (1, "\n", 1);
		ft_swap(data, data->xp, data->yp, 'l');
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			data->yp * data->width, data->xp * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			(data->yp - 1) * data->width, data->xp * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_left,
			(data->yp - 1) * data->width, data->xp * data->height);
	}
	else if (data->map[data->xp][data->yp - 1] == 'E'
		&& !open_the_door(data, 0))
	{
		ft_putnbr(++data->count);
		write (1, "\n", 1);
		exit (0);
	}
}
