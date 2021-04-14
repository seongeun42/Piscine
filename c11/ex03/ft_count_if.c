/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:29:32 by seongele          #+#    #+#             */
/*   Updated: 2021/04/12 21:36:33 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int cnt;

	cnt = 0;
	while (--length >= 0)
		if (f(tab[length]) != 0)
			++cnt;
	return (cnt);
}
