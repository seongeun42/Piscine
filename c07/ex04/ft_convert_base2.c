/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:44:53 by seongele          #+#    #+#             */
/*   Updated: 2021/04/10 22:17:53 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid_ch(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' ||
				base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
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
		++base;
		++i;
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

int		ft_atoi_base(char *str, char *base, int digit)
{
	int num;
	int tmp;
	int sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((tmp = change_num(*str, base)) != -1)
	{
		num *= digit;
		num += tmp;
		++str;
	}
	num = sign * num;
	return (num);
}
