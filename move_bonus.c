/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:40:46 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/27 17:33:02 by mkaoukin         ###   ########.fr       */
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

static void ft_exit(char c)
{
	if (c == 'E')
		exit (0);
	else
		exit (1);
}

void	ft_move_up_bonus(t_data *data)
{
	data = get_player_bonus((data)->map, data, 0, 'P');
	if (data->map[data->xp - 1][data->yp] == '0' ||
		data->map[data->xp - 1][data->yp] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_wall,
			0 * data->width, 0 * data->height);
		mlx_string_put(data->mlx, data->mlx_win,0.3 * data->width, 0.3 * data->height, 5 ,ft_itoa(++data->count));
		ft_swap(data, data->xp, data->yp, 'u');
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			data->yp * data->width, data->xp * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			data->yp * data->width, (data->xp - 1) * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_back,
			data->yp * data->width, (data->xp - 1) * data->height);
	}
	else if ((data->map[data->xp - 1][data->yp] == 'E' && !open_the_door(data, 0)) ||  data->map[data->xp - 1][data->yp] == 'A')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_wall,
			0 * data->width, 0 * data->height);
		mlx_string_put(data->mlx, data->mlx_win,0.3 * data->width, 0.3 * data->height, 5 ,ft_itoa(++data->count));
		ft_exit(data->map[data->xp - 1][data->yp]);
	}
}

void	ft_move_down_bonus(t_data *data)
{
	data = get_player_bonus((data)->map, data, 0, 'P');
	if (data->map[data->xp + 1][data->yp] == '0' ||
		data->map[data->xp + 1][data->yp] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_wall,
			0 * data->width, 0 * data->height);
		mlx_string_put(data->mlx, data->mlx_win,0.3 * data->width, 0.3 * data->height, 5 ,ft_itoa(++data->count));
		ft_swap(data, data->xp, data->yp, 'd');
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			data->yp * data->width, data->xp * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			data->yp * data->width, (data->xp + 1) * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_player,
			data->yp * data->width, (data->xp + 1) * data->height);
	}
	else if ((data->map[data->xp + 1][data->yp] == 'E' && !open_the_door(data, 0)) || data->map[data->xp + 1][data->yp] == 'A')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_wall,
			0 * data->width, 0 * data->height);
		mlx_string_put(data->mlx, data->mlx_win,0.3 * data->width, 0.3 * data->height, 5 ,ft_itoa(++data->count));
		ft_exit(data->map[data->xp - 1][data->yp]);
	}
}

void	ft_move_right_bonus(t_data *data)
{
	data = get_player_bonus((data)->map, data, 0, 'P');
	if (data->map[data->xp][data->yp + 1] == '0' ||
	data->map[data->xp][data->yp + 1] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_wall,
			0 * data->width, 0 * data->height);
		mlx_string_put(data->mlx, data->mlx_win,0.3 * data->width, 0.3 * data->height, 5 ,ft_itoa(++data->count));
		ft_swap(data, data->xp, data->yp, 'r');
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			data->yp * data->width, data->xp * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			(data->yp + 1) * data->width, data->xp * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_right,
			(data->yp + 1) * data->width, data->xp * data->height);
	}
	else if ((data->map[data->xp][data->yp + 1] == 'E' && !open_the_door(data, 0)) || data->map[data->xp][data->yp + 1] == 'A')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_wall,
			0 * data->width, 0 * data->height);
		mlx_string_put(data->mlx, data->mlx_win,0.3 * data->width, 0.3 * data->height, 5 ,ft_itoa(++data->count));
		ft_exit(data->map[data->xp - 1][data->yp]);
	}
}

void	ft_move_left_bonus(t_data *data)
{
	data = get_player_bonus((data)->map, data, 0, 'P');
	if (data->map[data->xp][data->yp - 1] == '0' ||
		data->map[data->xp][data->yp - 1] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_wall,
			0 * data->width, 0 * data->height);
		mlx_string_put(data->mlx, data->mlx_win,0.3 * data->width, 0.3 * data->height, 5 ,ft_itoa(++data->count));
		ft_swap(data, data->xp, data->yp, 'l');
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			data->yp * data->width, data->xp * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			(data->yp - 1) * data->width, data->xp * data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_left,
			(data->yp - 1) * data->width, data->xp * data->height);
	}
	else if ((data->map[data->xp][data->yp - 1] == 'E' && !open_the_door(data, 0)) || data->map[data->xp][data->yp - 1] == 'A')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_wall,
			0 * data->width, 0 * data->height);
		mlx_string_put(data->mlx, data->mlx_win,0.3 * data->width, 0.3 * data->height, 5 ,ft_itoa(++data->count));
		ft_exit(data->map[data->xp - 1][data->yp]);
	}
}