/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 01:54:01 by seongele          #+#    #+#             */
/*   Updated: 2021/04/10 19:07:17 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	size;
	int			*ptr;

	if (min >= max)
		return (0);
	size = max - min;
	*range = (int *)malloc(4 * size);
	if (!(*range))
		return (-1);
	ptr = *range;
	while (min < max)
		*ptr++ = min++;
	return (size);
}
