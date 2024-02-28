/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:35:20 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/27 15:18:23 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len(char **map)
{
	int	j;

	j = 0;
	while (map[j])
	{
		j++;
	}
	return (j);
}

static void	check_wall(char **map, char *line, int i, int j)
{
	int	l;

	l = 0;
	while (map[l])
		l++;
	while (line[++i])
	{
		if ((line[i] == '\n' && line[i + 1] == '\n') || line[0] == '\n'
			|| (line[i] == '\n' && line[i + 1] == '\0'))
			ft_error("new_line");
	}
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[0][i] != '1' || map[l - 1][i] != '1')
				ft_error("error_wall");
			if (map[j][0] != '1' || (map[j][i + 1] == '\0' && map[j][i] != '1'))
				ft_error("error_wall");
			if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'E'
				&& map[j][i] != 'C' && map[j][i] != 'P' && map[j][i] != 'A')
				ft_error("caracter not define");
		}
	}
}

static void	check_len(char **map)
{
	size_t	len;
	int		i;

	i = 1;
	len = ft_strlen(map[0], 0);
	while (map[i])
	{
		if (len != ft_strlen(map[i], 0))
			ft_error("error_size");
		i++;
	}
}

static void	check_component(char *map, int e, int	p, int	c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			c++;
		else if (map[i] == 'P')
			p++;
		else if (map[i] == 'E')
			e++;
		else if (map[i] == 'A')
			a++;
		i++;
	}
	if (p != 1)
		ft_error("error_player");
	if (c == 0)
		ft_error("error_collectible");
	if (e != 1)
		ft_error("error_exit");
	if (a == 0)
		ft_error("error_anime");
}

char	**parsing_bonus(char *name, t_data *data, char *line)
{
	char	**map;
	char	*buff;
	int		fd;

	fd = open(name, O_RDWR);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		line = ft_strjoin(line, buff);
		free (buff);
	}
	if (!line)
		ft_error("file_vide");
	map = ft_split(line, '\n');
	if (ft_strlen(map[0], 0) > 136 || len(map) > 136)
		ft_error("size_long");
	check_wall(map, line, -1, -1);
	check_len(map);
	check_component(line, 0, 0, 0);
	data = get_player_bonus(map, data, 1, 'P');
	free_all(map);
	map = ft_split(line, '\n');
	return (close(fd), free (line), map);
}