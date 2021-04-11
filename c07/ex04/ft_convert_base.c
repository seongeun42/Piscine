/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:47:41 by seongele          #+#    #+#             */
/*   Updated: 2021/04/10 22:17:29 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_valid(char *base);
int		ft_atoi_base(char *str, char *base, int digit);

int		cnt_size(int nb, int digit)
{
	int size;

	if (nb == 0)
		return (1);
	size = 0;
	while (nb > 0)
	{
		nb /= digit;
		++size;
	}
	return (size);
}

void	*ft_putnbr_base(int nbr, int digit, char *base)
{
	char	*num;
	int		size;

	size = cnt_size(nbr, digit);
	if (nbr < 0)
		size = cnt_size(-nbr, digit) + 2;
	else
		size = cnt_size(nbr, digit) + 1;
	num = (char *)malloc(size);
	num[--size] = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		num[0] = '-';
	}
	if (nbr == 0)
		num[--size] = base[0];
	while (nbr > 0)
	{
		num[--size] = base[nbr % digit];
		nbr /= digit;
	}
	return (num);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*num;
	int		fm_digit;
	int		to_digit;
	int		cov_num;

	if (!(fm_digit = is_valid(base_from)))
		return (0);
	if (!(to_digit = is_valid(base_to)))
		return (0);
	cov_num = ft_atoi_base(nbr, base_from, fm_digit);
	num = ft_putnbr_base(cov_num, to_digit, base_to);
	return (num);
}
