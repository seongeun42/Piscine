/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:18:33 by seongele          #+#    #+#             */
/*   Updated: 2021/04/06 15:09:59 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int facto;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	facto = 1;
	while (nb > 0)
		facto *= nb--;
	return (facto);
}
