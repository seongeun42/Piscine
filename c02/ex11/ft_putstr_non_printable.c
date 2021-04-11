/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:31:42 by seongele          #+#    #+#             */
/*   Updated: 2021/04/01 21:32:02 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_print(char c)
{
	if (c < 32 || c > 126)
		return (0);
	else
		return (1);
}

void	hex(unsigned char asc)
{
	char hex[3];
	char *base;

	base = "0123456789abcdef";
	hex[0] = '\\';
	hex[1] = base[asc / 16];
	hex[2] = base[asc % 16];
	write(1, hex, 3);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (!is_print(*str))
			hex(*str);
		else
			write(1, str, 1);
		str++;
	}
}
