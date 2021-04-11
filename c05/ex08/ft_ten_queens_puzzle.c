/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:41:47 by seongele          #+#    #+#             */
/*   Updated: 2021/04/06 01:06:10 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	queens(int r, char *q, int *count)
{
	char	c;
	int		i;

	c = '0' - 1;
	while (++c <= '9')
	{
		i = -1;
		while (++i < r)
		{
			if (c == q[i] || c == q[i] + (r - i) || c == q[i] - (r - i))
				break ;
		}
		if (i == r)
		{
			q[r] = c;
			if (r == 9)
			{
				*count = *count + 1;
				write(1, q, 11);
			}
			else
				queens(r + 1, q, count);
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	char	qen[11];
	int		count;
	int		row;
	int		col;

	count = 0;
	qen[10] = '\n';
	row = 0;
	col = -1;
	while (++col < 10)
	{
		qen[row] = '0' + col;
		queens(row + 1, qen, &count);
	}
	return (count);
}
