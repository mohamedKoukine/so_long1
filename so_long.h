/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:52:23 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/27 17:19:32 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjo_or_cat(char *s1, char *s2);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str, int flag);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
void	ft_error(char *err);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

typedef struct s_data
{
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_left;
	void	*img_trap;
	void	*img_right;
	void	*img_back;
	void	*img_door;
	void	*img_door_open;
	void	*img_collectible;
	void	*mlx_win;
	void	*mlx;
	int		width;
	int		height;
	int		xp;
	int		yp;
	int		count;
	char	**map;
}				t_data;

int		len(char **map);
void	check_map(char **map, char c);
t_data	*get_player(char **map, t_data *data, int l, char c);
void	put_wall(char **map, void *mlx, t_data *data);
void	put_floor(char **map, void *mlx, t_data *data);
void	put_door(char **map, void *mlx, t_data *data);
void	put_player(char **map, void *mlx, t_data *data);
void	ft_move_up(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_right(t_data *data);
void	ft_move_left(t_data *data);
void	put_collectible(char **map, void *mlx, t_data *data);
int		open_the_door(t_data *data, int k);
void	ft_putnbr(int n);
void	free_all(char **map);
char	**parsing(char *name, t_data *data, char *line);
//bonus
char	**parsing_bonus(char *name, t_data *data, char *line);
t_data	*get_player_bonus(char **map, t_data *data, int l, char c);
char	*ft_itoa(int n);
void	ft_move_up_bonus(t_data *data);
void	ft_move_down_bonus(t_data *data);
void	ft_move_right_bonus(t_data *data);
void	ft_move_left_bonus(t_data *data);

#endif