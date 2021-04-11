/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:27:22 by seongele          #+#    #+#             */
/*   Updated: 2021/03/30 21:41:12 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	div(int nb)
{
	char num;

	if (nb == 0)
		return ;
	div(nb / 10);
	num = '0' + (nb % 10);
	write(1, &num, 1);
}

void	ft_putnbr(int nb)
{
	char num;

	if (nb < 0)
	{
		write(1, "-", 1);
		div(-(nb / 10));
		num = '0' - (nb % 10);
		write(1, &num, 1);
	}
	else
	{
		div(nb / 10);
		num = '0' + (nb % 10);
		write(1, &num, 1);
	}
}
