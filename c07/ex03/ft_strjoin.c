/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:33:22 by seongele          #+#    #+#             */
/*   Updated: 2021/04/10 19:23:05 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	long long leng;

	leng = 0;
	while (str[leng] != 0)
		++leng;
	return (leng);
}

char	*copy(char *dest, char *str)
{
	while (*str != 0)
	{
		*dest = *str;
		++dest;
		++str;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	long long	leng;
	char		*all;
	char		*tmp;
	int			idx;

	if (!size)
	{
		all = (char *)malloc(1);
		all[0] = 0;
		return (all);
	}
	leng = 0;
	idx = 0;
	while (idx < size)
		leng += ft_strlen(strs[idx++]);
	all = (char *)malloc((ft_strlen(sep) * (size - 1)) + leng + 1);
	idx = 0;
	tmp = copy(all, strs[idx]);
	while (++idx < size)
	{
		tmp = copy(tmp, sep);
		tmp = copy(tmp, strs[idx]);
	}
	*tmp = 0;
	return (all);
}
