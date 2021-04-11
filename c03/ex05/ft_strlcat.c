/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 23:09:30 by seongele          #+#    #+#             */
/*   Updated: 2021/04/04 21:19:49 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int count_d;
	unsigned int count_s;

	count_s = ft_strlen(src);
	count_d = ft_strlen(dest);
	i = 0;
	j = count_d;
	while (*src != '\0' && i + count_d + 1 < size)
	{
		*(dest + j) = *src;
		src++;
		j++;
		i++;
	}
	if (i + count_d < size)
		*(dest + j) = '\0';
	if (size < count_d)
		i = count_s + size;
	else
		i = count_s + count_d;
	return (i);
}
