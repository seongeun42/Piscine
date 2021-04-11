/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 23:39:48 by seongele          #+#    #+#             */
/*   Updated: 2021/04/04 14:56:05 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alph(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (2);
	if (c >= '0' && c <= '9')
		return (3);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int is_first;

	i = 0;
	is_first = 1;
	while (str[i] != '\0')
	{
		if (is_alph(str[i]) == 0)
			is_first = 1;
		else
		{
			if (is_first && is_alph(str[i]) == 1)
				str[i] -= 32;
			else if (!is_first && is_alph(str[i]) == 2)
				str[i] += 32;
			is_first = 0;
		}
		i++;
	}
	return (str);
}
