/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:10:23 by seongele          #+#    #+#             */
/*   Updated: 2021/03/28 12:11:39 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int width, int length)
{
	int x;
	int y;

	if (width < 0 || length < 0)
		return ;
	y = length;
	while (y > 0)
	{
		x = width;
		while (x > 0)
		{
			if ((y == length && x == width) || (y == 1 && x == 1))
				ft_putchar('/');
			else if ((y == length && x == 1) || (y == 1 && x == width))
				ft_putchar('\\');
			else if (y != length && y != 1 && x != width && x != 1)
				ft_putchar(' ');
			else
				ft_putchar('*');
			x--;
		}
		ft_putchar('\n');
		y--;
	}
}
