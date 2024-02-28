/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:09:11 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/16 15:38:28 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str, int flag)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (flag == 0)
	{
		while (str[i])
			i++;
	}
	else
	{
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (i);
}

char	*ft_strjo_or_cat(char *s1, char *s2)
{
	char	*d;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_substr(s2, 0, ft_strchr(s2, '\n')));
	j = ft_strlen(s2, 1);
	if (ft_strchr(s2, '\n') > -1)
		j++;
	d = (char *)malloc(sizeof(char) * (ft_strlen(s1, 0) + j + 1));
	if (!d)
		return (NULL);
	j = 0;
	while (s1[i])
		d[i++] = s1[j++];
	j = 0;
	while (s2[j])
	{
		d[i++] = s2[j++];
		if (s2[j - 1] == '\n')
			break ;
	}
	return (d[i] = '\0', d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*d;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	d = malloc(sizeof(char) * (ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1));
	if (!d)
		return (NULL);
	j = 0;
	while (s1[i])
		d[i++] = s1[j++];
	j = 0;
	while (s2[j])
		d[i++] = s2[j++];
	d[i] = '\0';
	free(s1);
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	l;
	unsigned int	i;

	l = len;
	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s, 0) || l == 0)
		return (ft_strdup(""));
	if (start + l > ft_strlen(s, 0))
	{
		l = ft_strlen(s, 0) - start;
	}
	d = (char *)malloc(sizeof(char) * l + 1);
	if (!d)
		return (0);
	while (s[start] && i < l)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (!src)
		return (ft_strdup(""));
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof (char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
