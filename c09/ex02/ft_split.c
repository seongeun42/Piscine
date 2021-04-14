/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:10:28 by seongele          #+#    #+#             */
/*   Updated: 2021/04/11 00:32:47 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *sep)
{
	int i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (c == sep[i++])
			return (1);
	}
	return (0);
}

int		cnt_word(char *str, char *sep)
{
	char		*tmp;
	long long	cnt;

	cnt = 0;
	tmp = str;
	while (*tmp != 0)
	{
		while (*tmp && is_sep(*tmp, sep))
			++tmp;
		if (*tmp && !is_sep(*tmp, sep))
			++cnt;
		while (*tmp && !is_sep(*tmp, sep))
			++tmp;
	}
	return (cnt);
}

char	*save_word(char *str, char *sep)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !is_sep(str[i], sep))
		++i;
	word = (char *)malloc(i + 1);
	i = 0;
	while (str[i] && !is_sep(str[i], sep))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		i;

	words = (char **)malloc(sizeof(char *) * cnt_word(str, charset) + 1);
	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			++str;
		if (*str && !is_sep(*str, charset))
			words[i++] = save_word(str, charset);
		while (*str && !is_sep(*str, charset))
			++str;
	}
	words[i] = 0;
	return (words);
}
