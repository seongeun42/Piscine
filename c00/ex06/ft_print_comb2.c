/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:16:31 by seongele          #+#    #+#             */
/*   Updated: 2021/03/28 01:26:40 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	add(char *a, char *b)
{
	if (*b != '9')
		*b = *b + 1;
	else
	{
		*b = '0';
		*a = *a + 1;
	}
}

void	ft_print_comb2(void)
{
	char buf[7];

	buf[0] = '0';
	buf[1] = '0';
	buf[2] = ' ';
	buf[5] = ',';
	buf[6] = ' ';
	while (!(buf[0] == '9' && buf[1] == '8'))
	{
		buf[3] = buf[0];
		buf[4] = buf[1];
		while (buf[3] != '9' || buf[4] != '9')
		{
			add(&buf[3], &buf[4]);
			write(1, buf, 7);
		}
		add(&buf[0], &buf[1]);
	}
	write(1, "98 99", 5);
}
