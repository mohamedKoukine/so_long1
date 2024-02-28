/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:53:49 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/27 16:07:00 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_len(long n)
{
	int		j;

	j = 1;
	if (n < 0)
	{
		n = -n;
		j++;
	}
	while (n > 9)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char	*d;
	long	k;
	int		j;

	k = n;
	j = ft_len(n);
	d = (char *)malloc(sizeof(char) * j + 1);
	if (!d)
		return (NULL);
	d[j] = '\0';
	j--;
	if (n < 0)
		k = -k;
	while (j >= 0)
	{
		d[j] = (k % 10) + 48;
		k = (k / 10);
		if (n < 0 && j == 0)
			d[j] = '-';
		j--;
	}
	return (d);
}
