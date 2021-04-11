/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:44:39 by seongele          #+#    #+#             */
/*   Updated: 2021/04/06 16:11:22 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int sqr;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	sqr = 1;
	while (power-- > 0)
		sqr *= nb;
	return (sqr);
}
