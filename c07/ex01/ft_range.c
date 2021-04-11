/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:33:16 by seongele          #+#    #+#             */
/*   Updated: 2021/04/10 19:06:51 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long long	size;
	int			*array;

	if (min >= max)
		return (0);
	size = (long long)max - min;
	array = (int *)malloc(4 * size);
	if (array == 0)
		return (0);
	while (--size >= 0)
		array[size] = --max;
	return (array);
}
