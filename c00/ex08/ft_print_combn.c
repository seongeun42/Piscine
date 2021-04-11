/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:00:40 by seongele          #+#    #+#             */
/*   Updated: 2021/03/30 14:57:20 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	iter(char prev, int size, char args[], int n)
{
	args[size] = prev;
	while (++args[size] <= '0' + (10 - n + size))
	{
		if (size == n - 1)
			write(1, args, n + 2);
		else
			iter(args[size], size + 1, args, n);
	}
}

void	last_print(int n)
{
	char i;

	i = '0' + (10 - n);
	while (i <= '9')
	{
		write(1, &i, 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	num[n + 2];
	int		size;

	size = 0;
	num[0] = '0' - 1;
	num[n] = ',';
	num[n + 1] = ' ';
	while (++num[0] < '0' + (10 - n))
	{
		if (size == n - 1)
			write(1, num, n + 2);
		else
			iter(num[0], size + 1, num, n);
	}
	last_print(n);
}
