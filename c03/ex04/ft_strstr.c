/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:17:15 by seongele          #+#    #+#             */
/*   Updated: 2021/03/31 23:08:31 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *cmp_find;
	char *cmp_str;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		cmp_find = to_find;
		cmp_str = str;
		while (*cmp_find == *cmp_str && *cmp_find != '\0')
		{
			cmp_find++;
			cmp_str++;
		}
		if (*cmp_find == '\0')
			return (str);
		str++;
	}
	return (0);
}
