/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:55:06 by seongele          #+#    #+#             */
/*   Updated: 2021/04/12 20:46:50 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	add(int num1, int num2)
{
	return (num1 + num2);
}

int	sub(int num1, int num2)
{
	return (num1 - num2);
}

int	mul(int num1, int num2)
{
	return (num1 * num2);
}

int	div(int num1, int num2)
{
	return (num1 / num2);
}

int	mod(int num1, int num2)
{
	return (num1 % num2);
}
