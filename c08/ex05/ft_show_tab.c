/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:10:03 by seongele          #+#    #+#             */
/*   Updated: 2021/04/08 13:26:52 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_size(int size)
{
	char num;

	if (size <= 0)
		return ;
	print_size(size / 10);
	num = '0' + (size % 10);
	write(1, &num, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int idx;

	idx = 0;
	while (par[idx].str)
	{
		write(1, par[idx].str, par[idx].size);
		write(1, "\n", 1);
		if (par[idx].size == 0)
			write(1, "0", 1);
		else
			print_size(par[idx].size);
		write(1, "\n", 1);
		write(1, par[idx].copy, par[idx].size);
		write(1, "\n", 1);
		++idx;
	}
}
