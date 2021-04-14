/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:34:12 by seongele          #+#    #+#             */
/*   Updated: 2021/04/12 21:36:46 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int prev;
	int tmp;
	int i;

	prev = 0;
	i = -1;
	while (++i < length - 1)
	{
		tmp = f(tab[i], tab[i + 1]);
		if (prev == 0 && tmp != 0)
			prev = tmp;
		if ((prev < 0 && tmp > 0) || (prev > 0 && tmp < 0))
			return (0);
	}
	return (1);
}
