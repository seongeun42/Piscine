/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:56:07 by seongele          #+#    #+#             */
/*   Updated: 2021/04/07 23:09:33 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					size(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char				*ft_strdup(char *str)
{
	long long	len;
	char		*dest;

	len = 0;
	while (str[len])
		++len;
	dest = (char *)malloc(len + 1);
	dest[len] = '\0';
	while (--len >= 0)
		dest[len] = str[len];
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stt;
	int			idx;

	if (!(stt = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (0);
	idx = -1;
	while (++idx < ac)
	{
		stt[idx].size = size(av[idx]);
		stt[idx].str = av[idx];
		stt[idx].copy = ft_strdup(av[idx]);
	}
	stt[idx] = (t_stock_str){0, 0, 0};
	return (stt);
}
