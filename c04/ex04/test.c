/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:53:45 by seongele          #+#    #+#             */
/*   Updated: 2021/04/06 12:24:17 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		is_valid(char *base)
{
	int		i;
	char	*ptr;

	i = 0;
	if (*base == '+' || *base == '-' || *base == '\0')
		return (0);
	while (base[i] != '\0')
		i++;
	if (i == 1)
		return (0);
	i = 0;
	while (*base != '\0')
	{
		ptr = base + 1;
		while (*base != *ptr && *ptr != '\0')
		{
			if (*ptr == '+' || *ptr++ == '-')
				return (0);
		}
		if (*base == *ptr)
			return (0);
		base++;
		i++;
	}
	return (i);
}

void	print_num(int nb, int digit, char *base)
{
	char num;

	if (nb == 0)
		return ;
	print_num(nb / digit, digit, base);
	num = base[nb % digit];
	write(1, &num, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int digit;
	int num;

	if (!is_valid(base))
		return ;
	else
		digit = is_valid(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		print_num(-(nbr / digit), digit, base);
		num = base[-(nbr % digit)];
	}
	else
	{
		print_num(nbr / digit, digit, base);
		num = base[nbr % digit];
	}
	write(1, &num, 1);
}

int main()
{
	int num = 155482;
	char *base = "abcdgeca";

	ft_putnbr_base(num, base);
	return 0;
}
