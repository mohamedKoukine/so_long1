/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_par_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:38:31 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/27 15:57:34 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *err)
{
	int	i;

	i = 0;
	write (1, "Error\n", 6);
	while (err[i])
	{
		write (1, &err[i], 1);
		i++;
	}
	exit(1);
}

static void	flood_fill_bonus(char **map, int y, int x)
{
	if (x < 0 || y < 0 || !map[y] || (map[y][x] != 'P' && map[y][x] != '0'
		&& map[y][x] != 'C'))
		return ;
	map[y][x] = '3';
	flood_fill_bonus(map, y - 1, x);
	flood_fill_bonus(map, y + 1, x);
	flood_fill_bonus(map, y, x - 1);
	flood_fill_bonus(map, y, x + 1);
}

void	check_map(char **map, char c)
{
	int		i;
	int		j;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'E' && map[j - 1][i] != '3' && map[j + 1][i] != '3'
				&& map[j][i - 1] != '3' && map[j][i + 1] != '3')
				ft_error("map_is_not_valide");
		}
	}
	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'P' || map[j][i] == c)
				ft_error("map_is_not_valide");
		}
	}
}

t_data	*get_player_bonus(char **map, t_data *data, int l, char c)
{
	int		i;
	int		j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
			{
				data->xp = j;
				data->yp = i;
				break ;
			}
			i++;
		}
		j++;
	}
	if (l == 1)
	{
		flood_fill_bonus(map, data->xp, data->yp);
		check_map(map, 'C');
	}
	return (data);
}
