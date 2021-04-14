/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:15:45 by seongele          #+#    #+#             */
/*   Updated: 2021/04/12 21:35:58 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *rt;

	rt = (int *)malloc(sizeof(int) * length);
	while (--length >= 0)
		rt[length] = f(tab[length]);
	return (rt);
}
