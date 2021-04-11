/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:30:42 by seongele          #+#    #+#             */
/*   Updated: 2021/04/04 18:20:37 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid_ch(char *base)
{
	int i;

	i = 0;
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-' ||
				*base == ' ' || *base == '\n' || *base == '\t' ||
				*base == '\v' || *base == '\f' || *base == '\r')
			return (0);
		base++;
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int		is_valid(char *base)
{
	int		i;
	char	*ptr;

	if (!is_valid_ch(base))
		return (0);
	i = 0;
	while (*base != '\0')
	{
		ptr = base + 1;
		while (*base != *ptr && *ptr != '\0')
			ptr++;
		if (*base == *ptr)
			return (0);
		base++;
		i++;
	}
	return (i);
}

int		change_num(char str, char *base)
{
	int i;

	i = 0;
	while (str != base[i] && base[i] != '\0')
		i++;
	if (base[i] == '\0')
		return (-1);
	return (i);
}

void	add_num(int *num, int digit, char *str, char *base)
{
	while (*str >= 33 && *str <= 126)
	{
		if (change_num(*str, base) == -1)
			break ;
		else
		{
			*num *= digit;
			*num += change_num(*str, base);
		}
		str++;
	}
}

int		ft_atoi_base(char *str, char *base)
{
	int num;
	int sign;
	int digit;

	if (!is_valid(base))
		return (0);
	else
		digit = is_valid(base);
	num = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	add_num(&num, digit, str, base);
	num = sign * num;
	return (num);
}
