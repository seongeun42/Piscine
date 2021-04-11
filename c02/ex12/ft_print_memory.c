/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:26:56 by seongele          #+#    #+#             */
/*   Updated: 2021/04/08 14:27:06 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	chr_to_hex(unsigned char num)
{
	char *base;
	char h[2];

	base = "0123456789abcdef";
	h[0] = base[num / 16];
	h[1] = base[num % 16];
	write(1, h, 2);
}

void	memory_write(long long mem, int digit)
{
	int		x;
	char	h[digit];

	x = 16 - digit;
	while (x-- > 0)
		write(1, "0", 1);
	x = digit;
	while (mem > 0)
	{
		if (mem % 16 < 10)
			h[--x] = mem % 16 + '0';
		else
			h[--x] = mem % 16 % 10 + 'a';
		mem /= 16;
	}
	write(1, h, digit);
	write(1, ": ", 2);
}

void	ch_hex_write(unsigned char *addr, unsigned int size)
{
	int count;
	int range;
	int i;

	i = 1;
	count = 0;
	range = ((size / 16 == 0) ? size : 16);
	while (count < 16)
	{
		if (count < range)
			chr_to_hex(addr[count]);
		else
			write(1, "  ", 2);
		if (count % 2 == 1)
			write(1, " ", 1);
		count++;
	}
}

void	ch_write(unsigned char *addr, unsigned int size)
{
	int	count;
	int range;

	count = 0;
	range = ((size / 16 == 0) ? size : 16);
	while (count < range)
	{
		if (addr[count] < 32 || addr[count] > 126)
			write(1, ".", 1);
		else
			write(1, &addr[count], 1);
		++count;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	s;
	long long		x;
	void			*tmp;
	int				digit;

	s = 0;
	while (size != 0)
	{
		tmp = addr + s;
		x = (long long)tmp;
		digit = 0;
		while (x > 0)
		{
			x /= 16;
			digit++;
		}
		memory_write((long long)tmp, digit);
		ch_hex_write((unsigned char *)tmp, size);
		ch_write((unsigned char *)tmp, size);
		write(1, "\n", 1);
		size = (size > 16 ? size - 16 : 0);
		s = s + 16;
	}
	return (addr);
}
