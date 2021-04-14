/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:03:57 by seongele          #+#    #+#             */
/*   Updated: 2021/04/12 20:46:14 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd05.h"

int		ft_atoi(char *str)
{
	int num;
	int sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += (int)*str - 48;
		++str;
	}
	num *= sign;
	return (num);
}

void	ft_putnbr(int num)
{
	char n;

	if (num == 0)
		return ;
	if (num < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-(num / 10));
		n = '0' - (num % 10);
	}
	else
	{
		ft_putnbr(num / 10);
		n = '0' + (num % 10);
	}
	write(1, &n, 1);
}

int		is_op_valid(char *op)
{
	int i;

	i = 0;
	while (op[i] != 0)
		++i;
	if (i == 1)
	{
		if (op[0] == '+')
			return (0);
		if (op[0] == '-')
			return (1);
		if (op[0] == '*')
			return (2);
		if (op[0] == '/')
			return (3);
		if (op[0] == '%')
			return (4);
	}
	return (-1);
}

void	doop(char *num1, char *num2, char *op, int (*f[])(int, int))
{
	int n1;
	int n2;
	int opt;
	int res;

	n1 = ft_atoi(num1);
	n2 = ft_atoi(num2);
	opt = is_op_valid(op);
	if (n2 == 0 && opt == 3)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	if (n2 == 0 && opt == 4)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	res = f[opt](n1, n2);
	if (res == 0)
		write(1, "0", 1);
	else
		ft_putnbr(res);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int (*f[5])(int, int);

	f[0] = add;
	f[1] = sub;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	if (argc != 4)
		return (0);
	if (is_op_valid(argv[2]) == -1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	doop(argv[1], argv[3], argv[2], f);
	return (0);
}
